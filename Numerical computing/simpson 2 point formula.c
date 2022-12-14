#include<stdio.h>
#include<math.h>
int main()
{float x1,x2,e,h,x,s1,s2,s4,Sn,I0,I1,In;
int i=2,j;
printf("enter the boundary points and  acceptable error:-\n");
scanf("%f%f%f",&x1,&x2,&e);
h=(x2-x1)/2;
i=2;
s1=sin(x1)+sin(x2);
s2=0;
s4=sin(x1+h);
I0=0;
In=(s1+4*s4)*h/3;
do{
	s2+=s4;
	s4=0;
	x=x1+h/2;
	for(j=1;j<=i;j++)
	{s4=s4+sin(x);
	x+=h;
	}
	h/=2;
	i*=2;
	I0=In;
	In=(s1+2*s2+4*s4)*h/3;
}while(fabs((In-I0)/In)<=e);
printf("integration of this polynomial  = %f",In);
}

