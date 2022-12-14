#include<stdio.h>
int main()
{
int i,j,k,n;
float u,sum,x[100],arr[100][100];
printf("enter the order of system:-");
scanf("%d",&n);
for(i=0;i<n;i++){
for(j=0;j<=n;j++){
printf("enter the value of arr[%d][%d]: ",i,j);
scanf("%f",&arr[i][j]);
}
}
for(k=0;k<n-1;k++){
for(i=k+1;i<n;i++){
u=arr[i][k]/arr[k][k];
for(j=k;j<=n;j++){
arr[i][j]=arr[i][j]-u*arr[k][j];
}
}
}
  x[n-1]=arr[n-1][n]/arr[n-1][n-1];
  for(i=n-2;i>=0;i--){
   sum=0;
  for(j=i+1;j<n;j++){
  sum+=arr[i][j]*x[j];
}
x[i]=(arr[i][n]-sum)/arr[i][i];
}
for(i=0;i<n;i++){
printf("value of x[%d]= %f\n",i+1,x[i]);
}
}


