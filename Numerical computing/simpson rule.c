#include<stdio.h>
int main()
{ float h,sum=0,F[50],integral;
int n,i,j;
printf("enter no. of data : ");
scanf("%d",&n);
printf("enter value of h: ");
scanf("%f",&h);
for(i=0;i<n;i++){
printf("enter F[%d]: ",i);
scanf("%f",&F[i]);}
sum=(F[0]+F[n-1]);
for(j=1;j<n-1;j+=2)
sum=sum+4*F[j];
for(j=2;j<n-2;j+=2)
sum=sum+2*F[j];
integral=h*sum/3;
printf("integration of the function is = %f ",integral);
}
