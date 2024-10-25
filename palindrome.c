#include<stdio.h>
int main(){
    int n,c,r,reverse=0;
    printf("Enter the input : ");
    scanf("%d", &n);
    
    c=n;    


    while(n>0)
    {
       r = n%10;
       reverse = reverse*10+r;
       n= n/10;
    }
    printf("\nthe reverse number is: %d", reverse);
    


    if(c==reverse)
    {
        printf("\nThe number is palindrome: %d", reverse);
    }
    else
    {
        printf("\nThe number is not palindrome %d", reverse);
    }
}