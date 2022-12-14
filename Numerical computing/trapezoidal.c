#include<stdio.h>
int main()
{ float h,sum=0,arr[50],integral;
int n,i,j;
printf("enter no. of data :-\n");
scanf("%d",&n);
printf("enter value of h:-\n");
scanf("%f",&h);
for(i=0;i<n;i++){
    printf("enter arr[%d]:-\n",i);
    scanf("%f",&arr[i]);
	}
sum=(arr[0]+arr[n-1])/2;
for(j=1;j<n-1;j++)
sum=sum+arr[j];
integral=h*sum;
printf("integration of the function is = %f ",integral);
}
