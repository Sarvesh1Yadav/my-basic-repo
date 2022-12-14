#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int i,j,q,k,p,n,m;
float u,sum,x[100],arr[100][100],max,e,temp;
printf("enter the order of system and error e: ");
scanf("%d%f",&n,&e);
for(i=0;i<n;i++){
for(j=0;j<=n;j++){
printf("enter the value of arr[%d][%d]: ",i,j);
scanf("%f",&arr[i][j]);
}
}
for(k=0;k<n;k++){
	max=fabs(arr[k][k]);
	p=k;
	for(m=k+1;m<n;m++){
		if(fabs(arr[m][k])>max){
			max=fabs(arr[m][k]);
			p=m;}
		}
		if(max<=e){
		printf("Ill conditioned equation");
		exit(1);}
		else if(p=k)
		goto out;
		else{
			for(q=k;q<=n;q++){
				temp=arr[k][q];
				arr[k][q]=arr[p][q];
				arr[p][q]=temp;
				}
				goto out;			
			}
			out:
			for(k=0;k<n-1;k++){
               for(i=k+1;i<n;i++){
                 u=arr[i][k]/arr[k][k];
                 for(j=k;j<=n;j++){
                 arr[i][j]=arr[i][j]-u*arr[k][j];
                }
               }
            }
          x[n-1]=arr[n-1][n]/arr[n-1][n-1];
          for(i=n-2;i>=0;i--){
               sum=0;
              for(j=i+1;j<n;j++){
               sum+=arr[i][j]*x[j];
                 }
         x[i]=(arr[i][n]-sum)/arr[i][i];
           }
        for(i=0;i<n;i++){
          printf("value of x[%d]= %f\n",i+1,x[i]);
       }



		
	}
}
