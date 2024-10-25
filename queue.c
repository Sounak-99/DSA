#include<stdio.h>
#include<stdlib.h>
#define size 10
int front = -1, rear = -1;
int a[size];

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if(front == rear)
    { 
        printf("The deleted item is: %d", a[front]);
        front = rear = -1;
    }
    else
    {
       printf("The deleted item is: %d", a[front]);
       front++;
    }
}

void enqueue()
{
    int x;
    if(rear == size -1)
    {
        printf("queue is full");
    }
    else
    {
        printf("Enter the element to the queue: ");
        scanf("%d", &x);
       if(front == -1 && rear == -1)
       {
         front = rear = 0;
         a[rear] = x;
       }
       else
       {
         rear++;
         a[rear] = x;
       }
    }
}

void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
       for(i = front; i < rear + 1; i++)
       {
          if(i==rear)
          {
             printf("%d", a[i]);
          }
          else
          {
             printf("%d, ", a[i]);
          }
       }
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("The first element is: %d", a[front]);
    }
}

int main()
{
    int ch;
    printf("Enter (1) for enqueue/ (2) for dequeue/ (3) for display/ (4) for peek (5) for exit: ");

    while(1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Invalid choice");
        }
    }

    return 0;
}