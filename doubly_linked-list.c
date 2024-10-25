#include<stdio.h>
#include<stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *newnode, *temp;

struct node *create_doubly_linked_list()
{
   int ch;
   while(1)
   {
       newnode = (struct node*)malloc(sizeof(struct node));
       printf("Enter the data: ");
       scanf("%d", &newnode -> data);
       newnode -> next = NULL;
       newnode -> prev = NULL;
       if(head == NULL)
       {
          head = temp = newnode;
       }
       else
       {
           temp -> next = newnode;
           newnode -> prev = temp;
           temp = newnode;
       }
       
       printf("Do you want to continue then hit(0 or 1): ");
       scanf("%d", &ch);

       if(ch == 0)
       {
          break;
       }
   }

   return head;
}

//forward direction
void traverse_linked_list(struct node *head)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

//Backword direction
void backword_traverese_linked_list(struct node *head)
{
    struct node *ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    while(ptr != NULL)
    {
        printf("%d -> ", ptr -> data);
        ptr = ptr -> prev;
    }
}

//insert at the begining

struct node *insert_begining()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> next = NULL;
    newnode -> prev = NULL;

    //LOGIC

    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;

    return head;
}

//Insert at the end

struct node *insert_at_the_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);

    newnode -> next = NULL;
    newnode -> prev = NULL;

    //LOGIC
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
    

    return head;
}

int length()
{
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }

    return count;
}

//insert at any position

struct node *insert_at_any_position()
{
    int pos, i = 1, count;
    printf("Enter the postion: ");
    scanf("%d", &pos);

    //warning
    if(pos <= 0 || pos > (count = length()))
    {
        printf("Invalid postion\n");
    }
    else if(pos == 1)
    {
        printf("Begining insertion done");
        insert_begining();
    }
    else
    {
        //at any position
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode -> data);
        newnode -> next = NULL;
        newnode -> prev = NULL;
        
        temp = head;
        while(i<pos)
        {
            temp = temp -> next;
            i++;
        }
        newnode -> prev = temp;
        newnode -> next = temp -> next;
        temp -> next = newnode;
        newnode -> next -> prev = newnode;

    }

    return head;
}

//deletion method

//Delete from begining

void delete_from_begining()
{
   if(head == NULL)
   {
      printf("Linked list is empty");
   }
   else
   {
      head = temp;
      head = head -> next;
      if(head != NULL)
      {
        head ->prev = NULL;
      }
      else
      {
        tail = NULL;
      }
   }
   free(temp);
}

//deletion from last

void deletion_from_last()
{
    if(head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        temp = tail;
        tail -> prev -> next = NULL;
        tail = tail -> prev;
        free(temp);
    }
}

//Delete at any position

void delete_at_any_position()
{
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > length())
    {
        printf("Invalid position! please enter position between 1 to %d\n", length());
    }
    if(pos == 1)
    {
        delete_from_begining();
    }
    else if(pos == length())
    {
        deletion_from_last();
    }
    else
    {
        temp = head;
        while(i < pos)
        {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
    }
    
}

int main()
{
    struct node *head;
   
    

    int ch;
    printf("Choise Menu:");
    printf("\n1. for create a linked list:");
    printf("\n2. for insert from begining:");
    printf("\n3. for insert at any position:");
    printf("\n4. for insert from last position:");
    printf("\n5. for forward traverse linked list:");
    printf("\n6. for backword traverse linked list:");
    printf("\n7. for deletion from begining:");
    printf("\n8. for deletion from any position:");
    printf("\n9. for deletion at the last position:");
    printf("\n10. for Exit:");

    while(1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            head = create_doubly_linked_list();
            break;

            case 2:
            insert_begining();
            break;

            case 3:
            insert_at_any_position();
            break;

            case 4:
            insert_at_the_end();
            break;

            case 5:
            traverse_linked_list(head);
            break;

            case 6:
            backword_traverese_linked_list(head);
            break;

            case 7:
            delete_from_begining();
            break;

            case 8:
            delete_at_any_position();
            break;

            case 9:
            deletion_from_last();
            break;

            case 10:
            exit(0);
            break;

            default:
            printf("Invalid choice");
        }
    }
    

    return 0;
}