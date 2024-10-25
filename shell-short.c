#include<stdio.h>
void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void shell_short(int a, int n)
{
    int i,j,gap;
    for(i = 0; i + j / 2; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[j] > a[i])
            {
                i++;
                j++;
            }
            else if(a[j] < a[i])
            {
                swap(a,n);
                i++;
                j++;
            }
        }
    }
    
}