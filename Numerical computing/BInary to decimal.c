#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int j,n,sum=0;
	char binary[20];
	printf("Enter the Binary Number :");
	gets(binary);
	n=strlen(binary);
	for(j=0;j<n;j++)
	{
		if((binary[j]!='1')&&(binary[j]!='0'))
		{
			printf("\nPlease enter a Binary number !");
			exit(1);
		}
		
		sum+=(binary[n-1-j]-48)*(pow(2,j));
		
	}
	printf("Decimal equivalent of the given Binary Number : %d\n",sum);
}
