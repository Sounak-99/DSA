#include<stdio.h>
int main()
{
   int n,fact=1;
   printf("Enter the input: ");
   scanf("%d", &n);

   while(n>0)
   {
     fact = fact*n;
     n--;
   }
   printf("The factorial result is : %d", fact);

   return 0;
}