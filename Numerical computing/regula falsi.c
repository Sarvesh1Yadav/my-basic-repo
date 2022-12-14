#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float func(float x){
	float p;
	p=pow(x,2)-6*x+5;
	return p;
}
int main()
{int n,i;
float x;
printf("enter the number of iteration\n");
scanf("%d",&n);
 float x2,x0,x1,e,y1,y2,y0;
 	for(x=2;x<=7;x=x+0.5){
	printf("value of y(%.2f) at %.2f= %.2f\n",x,x,func(x));
   }
 printf("enter the value of X0,X1 from above data and e:-\n");
 scanf("%f%f%f",&x0,&x1,&e); 
 
  y0=func(x0);
  y1=func(x1);
   
  if((y0*y1)>0){
  printf("starting values are unsuitable\n");
  exit(1);}
  for(i=1;i<=n;i++)
  { x2=(x0*y1-x1*y0)/(y1-y0);
  y2=func(x2);
  y0=func(x0);
  y1=func(x1);
  if(fabs(y2)<=e){
  printf("convergent solution and the root is %f and the value of function at this point = %f",x2,y2);
  exit(1);
}
if((y0>0&&y2>0)||(y0<0&&y2<0))
  x0=x2;
  else
  x1=x2;
}
printf("equation doesn't converges in %d iteration\n",n);
  
  }
