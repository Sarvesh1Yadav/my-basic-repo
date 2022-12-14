#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{  int maxitr,i,j,k,n;
float arr[50][50],X[50],relerror,big,temp,sum,e;
printf("enter the order of matrix: ");
scanf("%d",&n);
printf("enter max no. of  iteration and error up to which it is acceptable:  ");
scanf("%d%f",&maxitr,&e);
for(i=0;i<n;i++){
  for(j=0;j<=n;j++){
   printf("enter the value of arr[%d][%d]:",i,j);
   scanf("%f",&arr[i][j]);
    }
}
for(i=0;i<n;i++)
  X[i]=0;
for(k=0;k<maxitr;k++){
big=0;
  for(i=0;i<n;i++){
    sum=0;
       for(j=0;j<n;j++){
        if(j!=i)
       sum+=arr[i][j]*X[j];
       }
    temp=(arr[i][n]-sum)/arr[i][i];
    relerror=fabs((X[i]-temp)/temp);
    if(relerror>big){
    big=relerror;
    X[i]=temp;}
}
if(big<=e){
printf("It converges to solution and values are-\n");
  for(i=0;i<n;i++)
   printf("values of X[%d]= %f\n",i+1,X[i]);
   exit(1);
  }
}
printf("It doesn't converge and the values are-\n");
for(i=0;i<n;i++)
printf("%f\n",X[i]);
}



