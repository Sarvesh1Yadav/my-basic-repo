#include<stdio.h>
#include <math.h>
int main()
{  int n,i;
	float sum,x,term;
	printf("enter value of x and n:-");
	scanf("%f%d",&x,&n);
	x=x*3.14/180;
	sum=x;
	term=x;
	for( i=1;i<n;i++)
	{ term=((-1)*pow(x,2)*term)/(2*i*(2*i+1));
	sum+=term;
		}
		printf("%f",sum);
		}
