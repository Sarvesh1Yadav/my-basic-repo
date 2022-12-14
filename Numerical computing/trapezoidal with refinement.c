#include<stdio.h>
#include<math.h>
int main(){
	int i,j,k;
	float x1,x,h,e,F[50],s1,I1,I0;
	printf("enter the value of x1,k,h,e:-\n");
	scanf("%f%d%f%f",&x1,&k,&h,&e);
	x=x1;
	for(i=1;i<=k;i++)
	{F[i]=sin(x);
	x=x+h;
	}
	s1=(F[1]+F[k])/2;
	for(j=2;j<=(k-1);j++)
	s1=s1+F[j];
	I1=h*s1;
	i=k-1;
	do{
		I0=I1;
		x=x1+h/2.0;
		for(j=1;j<=i;j++)
		{s1=s1+sin(x);
		x+=h;
		}
		i=2*i;
		h=h/2.0;
		I1=s1*h;
	}while(fabs((I1-I0)/I0)<=e);
	printf("\nIntegration of the sin series = %f",I1);
}
