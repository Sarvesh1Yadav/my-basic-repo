#include<stdio.h>
int main()
{ int a=0,b=1,n,i;
   printf("Enter no. of terms\n");
   scanf("%d",&n);
	long c=a+b;
	printf("%d %d %ld",a,b,c);
	for( i=3;i<n;i++)
	  {a=b;
	  b=c;
	  c=a+b;
	  if(c>0)
	printf(" %ld",c);}
	}
