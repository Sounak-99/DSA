#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create_linked_list()
{
    struct node *head = NULL;
    struct node *newnode, *temp;
    
    int ch;
    while(1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the input: ");
        scanf("%d", &newnode -> data);
        newnode -> next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue yes for(1) no for(0): ");
        scanf("%d", &ch);

        if (ch == 0)
        {
            break;
        }
        
    }

    return head;
}

void traverse_linked_list(struct node *head)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
       printf("%d -> ", ptr -> data);
       ptr = ptr -> next;
    }
    printf("NULL\n");
    
}

int main()
{
    struct node *head;
    head = create_linked_list();
    traverse_linked_list(head);

    return 0;
}
