#include<stdio.h>
int main()
{
	int bin[100];
	int n,i,j,a,m=0;
	printf("Enter the decimal number :");
	scanf("%d",&n);
	for(i=n,j=0;i>0;i/=2,j++)
	{
		a=i%2;
		bin[j]=a;
		m++;
	}
	printf("binary equivalent is : ");
	for(i=m-1;i>=0;i--)
	{
		printf("%d",bin[i]);
	}
	return 0;
}
