#include <iostream>
using namespace std;
int main()
{ int a=0,b=1,c=a+b;
	cout<<a<<" "<<b<<" "<<c;
	for(c=1;c<=100;)
	{ a=b;
		b=c;
		c=a+b;
		if(c<100)
		cout<<" "<<c;
		}
		}
