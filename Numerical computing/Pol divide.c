#include <stdio.h>
int main()
{
    int n,i;
    float r;
    printf("enter the degree of polynomial :");
    scanf("%d",&n);
    printf("enter the value of r :");
    scanf("%f",&r);
    float b[n];
    int arr[n+1];
    for(i=n;i>=0;i--)
    {
       printf("enter coefficient a[%i]",i);
       scanf(" %d",&arr[i]);
    }
    b[n-1]=arr[n];
    for(i=1;i<=n-1;i++)
     {
    b[n-(i+1)]=arr[n-i] + r*b[n-i];
     }
     for(i=0;i<=n-1;i++)
      {
        printf("\nCoefficient of x^[%i]=%.2f",i,b[i]);
      }
    return 0;
}
