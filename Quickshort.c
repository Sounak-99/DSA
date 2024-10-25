#include<stdio.h>
int partion(int a[], int low, int high)
{
    int pivot = a[low];
    int p = low;
    int q = high;
    int temp;

    do{

     
    
        while(a[p]<=pivot)
       {
          p++;
       }

       while(a[q]>pivot)
       {
          q--;
       }
       
       //swapping between p and q
       if(p<q)
       {
          temp = a[p];
          a[p] = a[q];
          a[q] = temp;
       }
       
       //swapping between q and pivot
    }while(p<q);
    {  
      temp = a[low];
      a[low] = a[q];
      a[q] = temp;
      return q;
    }
       

}

void quickshort(int a[], int low, int high)
{
    int partionindex;

    if(low<high)
    {
        partionindex = partion(a,low,high);
        quickshort(a,low,partionindex-1);
        quickshort(a,partionindex+1,high);
    }
}

void printarray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
}

int main()
{
    int a[] = {35,50,10,20,90,45,80};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\nprint the unsorted array: ");
    printf("\n");
    printarray(a,n);
    quickshort(a,0,n-1);
    printf("\n");
    printf("\nprint the sorted array: ");
    printf("\n");
    printarray(a,n);
    printf("\n");

    return 0;
}


