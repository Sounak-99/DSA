#include<stdio.h>
int main()
{
    int n,r;
    printf("Enter the input: ");
    scanf("%d", &n);
    int bin = 0;
    int var,mar;  

    while(n > 0)
    {
      r = n % 2;
      bin = 0 + 1 * r;
      n = n / 2;
    }

    printf("\nThe binary number is: %d %d %d", bin, bin, bin);
    return 0;
}
