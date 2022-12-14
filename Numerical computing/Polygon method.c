#include<stdio.h>
#include<math.h>
float f(float x,float y){
	return -(x*y);
}
int main() 
{
	float x1,x2,y1,xh,yh,y2,y,h,s1,s2,xf;
	printf("enter the value of  x1,y1,h and xf:");
	scanf("%f%f%f%f",&x1,&y1,&h,&xf);

	while(x1<=xf)
	{
		printf("\nAt x1= %f  y1= %f",x1,y1);
		s1=f(x1,y1);
		x2=x1+h;
		xh=x1+h/2;
		yh=y1+(h/2)*s1;
		s2=f(xh,yh);
		y2=y1+h*s2;
		x1=x2;
		y1=y2;
	}
	return 0;
}
