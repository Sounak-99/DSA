#include<stdio.h>
void insurt(int a[], int n)
{
    int i;
    int j;
    for(i=1;i<n;i++)
    {
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = temp;
    }
}

void printarray(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}

int main(){
    
    int a[] = {5, 4, 10, 1, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
   

    printf("Print the unsorted array: \n");
    printarray(a,   n);
    printf("\n");

    insurt(a,   n);
    printf("Print the sorted array : \n");
    printarray(a,  n);
    

    return 0;
}
