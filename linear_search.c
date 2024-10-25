#include<stdio.h>
int fun(int a[], int k, int key)
{
    int i;
    for(i=0;i<k;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }

    return -1;
}


void input( int a[], int k)
{
    int i;
    for(i = 0; i < k; i++)
    {
        printf("Enter the eliment of array: ");
        scanf("%d, ", &a[i]);
    }
}


void print(int a[], int k)
{
    int i;
    for(i = 0; i < k; i++)
    {
       printf("%d, ", a[i]);
    }
}


int main()
{
    int k;
    printf("Enter the range of the array: ");
    scanf("%d", &k);
    int a[k];
    input(a,k);
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    int result;
    print(a,k);
    printf("\n");
    result = fun(a, k, key);
    
    if(result == -1)
    {
        printf("Eliment is not found in the array");
    }
    else
    {
        printf("The eliment is in the index of : %d", result);
    }

    return 0;
}