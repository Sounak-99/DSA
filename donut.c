#include <stdio.h>
#include <math.h>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>  // For Sleep()
    void clear_screen() {
        system("cls");  // Clear screen for Windows
    }
#else
    #include <unistd.h>  // For usleep() in Unix-like systems
    void clear_screen() {
        printf("\033[H\033[J");  // Clear screen for Unix-like systems
    }
#endif

#define screen_width 80  // Example screen width
#define screen_height 24  // Example screen height

const float theta_spacing = 0.07;
const float phi_spacing = 0.02;

const float R1 = 1;
const float R2 = 2;
const float K2 = 5;
const float K1 = screen_width * K2 * 3 / (8 * (R1 + R2));

void render_frame(float A, float B) {
    // Precompute sines and cosines of A and B
    float cosA = cos(A), sinA = sin(A);
    float cosB = cos(B), sinB = sin(B);

    // Initialize output array and z-buffer
    char output[screen_height][screen_width];
    float zbuffer[screen_height][screen_width];

    // Initialize arrays
    for (int j = 0; j < screen_height; j++) {
        for (int i = 0; i < screen_width; i++) {
            output[j][i] = ' ';
            zbuffer[j][i] = -INFINITY;  // Set z-buffer to negative infinity initially
        }
    }

    // Theta goes around the cross-sectional circle of a torus
    for (float theta = 0; theta < 2 * M_PI; theta += theta_spacing) {
        float costheta = cos(theta), sintheta = sin(theta);

        // Phi goes around the center of revolution of a torus
        for (float phi = 0; phi < 2 * M_PI; phi += phi_spacing) {
            float cosphi = cos(phi), sinphi = sin(phi);

            // The x, y coordinate of the circle, before revolving (factored out of the above equations)
            float circlex = R2 + R1 * costheta;
            float circley = R1 * sintheta;

            // Final 3D (x, y, z) coordinate after rotations
            float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;
            float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;
            float z = K2 + cosA * circlex * sinphi + circley * sinA;
            float ooz = 1 / z;  // "one over z"

            // x and y projection
            int xp = (int)(screen_width / 2 + K1 * ooz * x);
            int yp = (int)(screen_height / 2 - K1 * ooz * y);

            // Ensure xp and yp are within screen bounds
            if (xp >= 0 && xp < screen_width && yp >= 0 && yp < screen_height) {
                // Calculate luminance
                float L = cosphi * costheta * sinB - cosA * costheta * sinphi -
                          sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);

                // If L > 0, surface is visible
                if (L > 0) {
                    if (ooz > zbuffer[yp][xp]) {  // Z-buffer check
                        zbuffer[yp][xp] = ooz;
                        int luminance_index = (int)(L * 8);  // Convert L to an index
                        if (luminance_index >= 0 && luminance_index < 12) {
                            output[yp][xp] = ".,-~:;=!*#$@"[luminance_index];
                        }
                    }
                }
            }
        }
    }

    // Clear the screen
    clear_screen();

    // Display the output array
    for (int j = 0; j < screen_height; j++) {
        for (int i = 0; i < screen_width; i++) {
            putchar(output[j][i]);
        }
        putchar('\n');
    }
}

int main() {
    float A = 0, B = 0;  // Initial angles
    while (1) {
        render_frame(A, B);
        A += 0.04;
        B += 0.02;
        #ifdef _WIN32
            Sleep(30);  // Sleep for 30ms on Windows
        #else
            usleep(30000);  // Sleep for 30ms on Unix-like systems
        #endif
    }
    return 0;
}

