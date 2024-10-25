#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define capacity 10

int top = -1, a[capacity];

void push()
{
    int x;
    if(top == capacity - 1)
    {
        printf("The stact is overflowed");
    }
    else
    {
        printf("Enter the eliment on the stack: ");
        scanf("%d", &x);
        top = top + 1;
        a[top] = x;

    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is underflowed");
    }
    else
    {
        printf("pop eliment %d", a[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    for(i = top; i >= 0; i--)
    {
        if(top == -1)
        {
            printf("stack is empty");
        }
        else
        {
           printf("\n%d", a[i]);
           printf("\n");
        }
    }
}

int main()
{
    int ch;
    printf("press 1for push, 2for pop, 3for show, 4for end: ");
    while(1)
    {
        printf("\nEnter the choise: ");
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
            printf("Invvalid");
        }
      
    }

   return 0;
}
