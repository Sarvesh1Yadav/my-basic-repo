#include<stdio.h>
#include<math.h>
int main()
{int i;
float X[50],R[50],I,a,b,F[50],p,q;
printf("enter lower and upper limit: ");
scanf("%f%f",&a,&b);
for(i=1;i<5;i++)
{printf("enter R[%d] and X[%d]:-",i,i);
scanf("%f%f",&R[i],&X[i]);
}
p=(a+b)/2;
q=(b-a)/2;
I=0;
for(i=1;i<5;i++)
{ F[i]= sin(p+q*X[i]);
I=R[i]*F[i]+ I;
}
I=q*I;
printf("\n%f",I);
}
