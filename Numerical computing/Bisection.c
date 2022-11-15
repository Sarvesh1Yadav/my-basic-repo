#include<stdio.h>
#include<math.h>
int sign(int,int);
float func(float);
int main()
{int n,i;
int a[50];
	float x;
	for(x=1;x<=10;x=x+0.5){
	printf("value of y(%.2f) at %.2f= %.2f\n",x,x,func(x));}
 float x2,p,x0,x1,e,y1,y2,y0;
 int arr[100 ];
 printf("enter the initial guess of X0 and X1 from above tabulation and  e:-\n");
 scanf("%f%f%f",&x0,&x1,&e); 
 /*	for( i=0;i<=n;i++)
	{ printf("enter the value of a[%d]:",i);
		scanf("%d",&a[i]);
		}*/
  y0=func(x0);
  y1=func(x1);
   i=0;
  if((y0*y1)>0)
  printf("starting values are unsuitable\n");
  
  while((fabs((x1-x0)/x1))>e)
  {
   x2=(x1+x0)/2.0;
   y2=func(x2);
  y0=func(x0);
   y1=func(x1);
  i++;
  if((y0>0&&y2>0)||(y0<0&&y2<0))
  x0=x2;
  else
  x1=x2;
}
printf("root of the equation is  %.4f at %dth iteration",x2,i);
}
float func(float x){
	float p;
	p=8*x*x*x-2*x-1;
	return p;
	}
