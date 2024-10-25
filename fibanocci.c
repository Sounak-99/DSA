#include<stdio.h>
int main(){
    int f1 = 0, f2 = 1,n,i=0;
    printf("Enter the fibanocci sequence: ");
    scanf("%d", &n);

    while(i<n)
    { 
       f1 = f2 + f1;

       i++;
    }
    printf("\nThe series is : %d", f1);
    return 0;
}