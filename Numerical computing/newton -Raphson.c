#include <stdio.h>
#include<math.h>
#include<stdlib.h>
float func1(float x){
    float p;
    p=pow(x,3)-4*x+1;
    return p;
}
float func2(float x){
    float p;
    p=3*pow(x,2)-4;
    return p;
}
int main()
{
    int n,i;
    float x,x1,del,epsilon,r,y1,y2;
    	for(x=1;x<=3;x=x+0.5){
	printf("value of y(%.2f) at %.2f= %.2f\n",x,x,func1(x));}
    printf("\nenter the value of x from above data\n");
    scanf("%f",&x);
     printf("enter the value of  delta,epsilon and no. of iteation\n");
    scanf("%f%f%d",&del,&epsilon,&n);
    for(i=1;i<=n;i++)
    { y1=func1(x);
      y2=func2(x);
      r=y1/y2;
       if(fabs(y2)<=del){
       printf("slope is too small  at %f and the value of function and slope = %f and %f",x,y1,y2);
       exit(1);
       }
       x1=x-r;
       if(fabs((x1-x)/x1)<epsilon){
       printf("function converges to root at %f and the value of function is =%f at %dth iteration ",x1,y1,i);
       exit(1);
       }
       x=x1;
    }
     printf("function doesn't converges in %d iteration",n);  
    return 0;
}


