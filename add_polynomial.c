#include<stdio.h>
#include<math.h>
int main()
{
   static int a[10], b[10];
   int n1,n2,sum[10];
   printf("Enter the degree of the 1st polynomial: ");
   scanf("%d", &n1);
   for(int i = 0; i <= n1; i++)
   {
      printf("\nEnter the coefficient of x^ %d: ", i);
      scanf("%d", &a[i]);
   }
   printf("\n");
   printf("Enter the degree of the 2nd polynomial: ");
   scanf("%d", &n2);
   for(int i = 0; i <= n2; i++)
   {
      printf("\nEnter the coefficient of x^%d: ", i);
      scanf("%d", &b[i]);
   }
   printf("\n");
   for(int i = 0; i <=n1; i++)
   {
      printf("%+dx^%d", a[i], i);
   }
   printf("\n");
   for(int i = 0; i <= n2; i++)
   {
      printf("%+dx^%d", b[i], i);
   }
   printf("\n");
    if(n2 > n1)
    {
        n1 = n2;
        printf("\n");
    }
   for(int i = 0; i <= n1; i++)
   {
      sum[i] = a[i] + b[i];
      printf("%+dx^%d", sum[i], i);
   }

   return 0;
   
}