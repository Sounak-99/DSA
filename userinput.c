/*#include<stdio.h>
int swap(int a, int b)
{
    a = a - b;
    b = a - b;
    a = a - b;
    return(a,b);
}

int main()
{
   int a,b;
   printf("Enter the input of a: ");
   scanf("%d", &a);
   printf("Enter the input of b: ");
   scanf("%d", &b);
   int s = swap(a,b);
   printf("\nThe result of a: %d", s);
   printf("\nThe result of b: %d", s);
   return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#define size 10

int top = -1, a[size];

void push(){
    int x;
    if(top == size - 1)
    {
        printf("Stack is overflowed");
    }
    else
    {
        printf("Enter the element to push in the stack: ");
        scanf("%d", &x);
        top++;
        a[top] = x;
    }
}

void pop(){
   if(top == -1)
   {
      printf("stack is underflowed");
   }
   else
   {
      printf("The poped element from the stack is: %d", a[top]);
      top--;
   }
}

void display()
{
    int i;
    for(i = top; i >= 0; i--)
    {
        if(top == -1)
        {
            printf("The stack is empty");
        }
        else
        {
            printf("%d\n", a[i]);
        }
    }
}


int main()
{
    int ch;
    printf("Enter(1) for push/ Enter(2) for pop/ Enter (3) for display/ Enter (4) for exit: ");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid");
        }
    }

    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#define size 5

int rare = -1, front = -1, a[size];

void enqueue()
{
    int x;
    if(rare == size - 1)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Enter the input for enqueue: ");
        scanf("%d", &x);
        if(rare == -1 && front == -1)
        {
            rare = front = 0;
            a[rare] = x;
        }
        else
        {
            rare++;
            a[rare] = x;
        }
    }
}

void dequeue()
{
    if(front == -1 && rare == -1)
    {
        printf("The Queue is empty");
    }
    else if(front == rare)
    {
        printf("The deleted item is %d", a[front]);
        front = rare = -1;
    }
    else
    {
        printf("The deleted item is %d", a[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == -1 && rare == -1)
    {
        printf("The Queue is empty");
    }
    else
    {
        for(i = front; i < rare + 1; i++)
        {
            if(i == rare)
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
    int i;
    if(front == -1 && rare == -1)
    {
        printf("The Queue is empty");
    }
    else
    {
        printf("The first element of the Queue is: %d", a[i]);
    }
}

int main()
{
    int ch;
    printf("Enter(1) for Enqueue/ (2) for dequeue/ (3) for display/ (4) for peek/ (5) for exit: ");
    while(1)
    {
        printf("\nEnter your choice: ");
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
           printf("Invalid");
       }
    }
    return 0;
}