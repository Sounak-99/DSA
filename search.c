#include<stdio.h>
int search(int a[], int n, int key)
{
   int i;
   for(i = 0; i < n; i++)
   {
       if(a[i]==key)
       {
          return i;
       }
   }

   return -1;
}

void user_input(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter the array eliments: ");
        scanf("%d", &a[i]);
    }
}


void print_array(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(i==n-1)
        {
            printf("%d", a[i]);
        }
        else
        {
            printf("%d, ", a[i]);
        }
    }
}

int main()
{
    int n;
    printf("Enter the range of the array: ");
    scanf("%d", &n);
    printf("\n");
    int a[n];
    user_input(a,n);
    printf("\n");
    int key;
    printf("Enter the key eliment: ");
    scanf("%d", &key);
    int result = search(a,n,key);
    if(result == -1)
    {
        printf("\nThe eliment is not found in the array");
    }
    else
    {
        printf("\nThe eliment is found at the index of: %d", result);
    }
    printf("\n");
    printf("\nThe array is: ");
    print_array(a,n);
    

    return 0;
}