#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 100

int top = -1, a[maxsize];

void push()
{
    int x;
    if(top == maxsize - 1)
    {
        printf("\nStack is overflowed");
    }
    else
    {
        printf("\nEnter the element to push: ");
        scanf("%d", &x);
        top++;
        a[top] = x;
    }
}
void pop()
{
    if(top == - 1)
    {
        printf("\nThe stack is underflowed");
    }
    else
    {
        printf("\nTop poped element: %d", a[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("\nstack is empty");
    }
     else
    {
        for(i = top; i >= 0; i++)
        {
            printf("\n%d", a[i]);
            printf("\n");
        }
    }
}

int main()
{
    
    int ch;
    printf("Enter (1)for push (2) for pop (3) for display (4) for exit: ");

    while(1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        printf("\n");
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
            printf("invalid");
        }
    }
   return 0;
}