#include<stdio.h>
int main()
{
	int i,j,n;
	float x0,x[100],f[100],sum,prodfunc;
	printf("Enter no. of  tabulated points :");
	scanf("%d",&n);
	printf(" Enter the value of X at which you want to estimate functional value :");
	scanf("%f",&x0);
	for(i=1;i<=n;i++)
	{
		printf("Enter X[%d] :",i);
		scanf("%f",&x[i]);
		printf("Enter f[%d] :",i);
		scanf("%f",&f[i]);
	}
	sum=0;
	for(i=1;i<=n;i++)
	{
		prodfunc=1;
		for(j=1;j<=n;j++)
		{
			if(j!=i)
			prodfunc*=(x0-x[j])/(x[i]-x[j]);
		}
		sum+=f[i]*prodfunc;
	}
	printf("Functional value at point %f = %f",x0,sum);
	
	return 0;
}
