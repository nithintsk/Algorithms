#include <iostream>
#include<math.h>
using namespace std;

long power(int,int,int);
int count=0;

int main()
{
	while(1) {
		cout<<"Enter the base a and the power n.\n";
		int a,n;
		cout<<"Enter a: ";
		cin>>a;
		cout<<"Enter n: ";
		cin>>n;
		int a_square = a*a;
		cout<<"a^n is : "<<power(a,a_square,n)<<"\n";
		cout<<"Total number of return values: "<<count<<"\n";
		system("pause");
		count=0;
	}
}

long power (int a, int asquare, int n)
{
	if (n == 0) return 1;
	if (n == 1)
	{
		count++;
		return a;
	}
	if (n == 2)
	{
		count++;
		cout<<"Iteration "<<count<<" where val of n="<<n<<" returned "<< asquare<<"\n";
		return asquare;
	}
	else 
	{
		if (n%2 != 0)
		{
			
			long val = power(a,asquare,n/2);
			count++;
			cout<<"Iteration "<<count<<" where val of n="<<n<<" returned "<< val*val*a<<"\n";
			return (val*val*a);
		}
		else 
		{
			long val = power(a,asquare,n/2);
			count++;
			cout<<"Iteration "<<count<<" where val of n="<<n<<" returned "<< val*val<<"\n";
			return (val*val);
		}
		//cout<<"Floor = "<<floor(n/2.0)<<"\n";
		//cout<<"Ceil = "<<ceil(n/2.0)<<"\n";
		//long val = power(a,asquare,floor(n/2.0)) * power (a,asquare,ceil(n/2.0));
		//cout<<"Iteration "<<count<<" returned "<< val<<"\n";
		//return val;
	}
	
}
