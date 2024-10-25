#include<stdio.h>
void swap(int *xp, int *yp)
{
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}

void selectionsort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
       int min = i;
       for(int j = i + 1; j < n; j++)
       {
          if(a[j] < a[min])
          {
             min = j;
          }
       }

       if(min!=i)
       {
         swap(&a[i], &a[min]);
       }
    }
}

void printarray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}

int main()
{
    int a[] = {7, 2, 9, 1, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Print the unsorted arrray : \n");
    printarray(a,n);
    printf("\n");
    selectionsort(a,n);
    printf("Print the sorted array: \n");
    printarray(a,n);

    return 0;
}