#include<stdio.h>
#include<math.h>
int main()
{float x1,x2,e,h,x,s1,I0,I1;
int i=1,j;
printf("enter the boundary points and  acceptable error:-\n");
scanf("%f%f%f",&x1,&x2,&e);
h=x2-x1;
s1=(sin(x1)+sin(x2))/2;
I1=h*s1;
do{
	x=x1+h/2.0;
	for(j=1;j<=i;j++){
		s1=s1+sin(x);
		x=x+h;
	}
	i=2*i;
	h=h/2.0;
	I0=I1;
	I1=h*s1;
}while(fabs((I1-I0)/I1)<=e);
printf("integration of this eqation  = %f",I1);
}
