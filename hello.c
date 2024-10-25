#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("Enter the input: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        sum = n*(n+1)/2;

    }
    printf("The sum is: %d", sum);

    return 0;
}