#include<stdio.h>
int main()
{
   int n,r,arm=0,ar;
   printf("Enter the input: ");
   scanf("%d", &n);

   ar = n;

   while(n!=0)
    {
        r = n % 10;
        arm = arm + (r*r*r);
        n = n/10;
    }

    
    if(ar==arm)
    {
        printf("\nThe number is armstrong : %d", arm);

    }
    else
    {
        printf("\nThe number is not armstrong: %d", arm);
    }
}