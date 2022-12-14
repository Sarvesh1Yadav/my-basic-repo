#include<stdio.h>
 float func(float x,float y){
 	float f;
 	f=-(x*y);
 	return f;
 }
int main()
{float x1,x2,y2,y1,h,Xf,s1,s2;
printf("enter x1,y1,h and Xf:-\n");
scanf("%f%f%f%f",&x1,&y1,&h,&Xf);
while(x1<=Xf)
{printf(" %f %f\n",x1,y1);
s1=func(x1,y1);
x2=x1+h;
y2=y1+h*s1;
s2=func(x2,y2);
y2=y1+h*(s1+s2)/2;
x1=x2;
y1=y2;
}
}
