#include <stdio.h>
int main()
{ int n,i;
	float x,p;
	int a[100];
	printf("enter the value of x and n:");
	scanf("%f%d",&x,&n);
	for( i=0;i<=n;i++)
	{ printf("enter the value of a[%d]:",i);
		scanf("%d",&a[i]);
		}
		p=a[n];
		for(i=(n-1);i>=0;i--)
		{p=a[i]+x*p;
		}
		printf("value of this polynomial = %f",p);
		}
