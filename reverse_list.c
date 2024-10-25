#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct node
{
    int info;
    char str[MAX_STRING_LENGTH];
    struct node *next;
};

typedef struct node ND;

int main() {
    ND *start = NULL, *temp;
    char continue_input;
    
    do {
        temp = (ND*)malloc(sizeof(ND));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return 1;  
        }

        printf("\nEnter an integer value: ");
        scanf("%d", &temp->info);
       
        while (getchar() != '\n');
        
        printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
        fgets(temp->str, MAX_STRING_LENGTH, stdin);
        
        temp->str[strcspn(temp->str, "\n")] = '\0';
        
        temp->next = start;
        start = temp;

        printf("\nWant to continue? (y/n): ");
        continue_input = getchar();
       
        while (getchar() != '\n');

    } while (toupper(continue_input) != 'N');

    // Print the linked list elements
    printf("\nElements of the linked list are:\n");
    while (start != NULL) {
        printf("%d [%s] <- ", start->info, start->str);
        ND *temp = start;
        start = start->next;
        free(temp);  
    }
    printf("NULL\n");

    return 0;
}
