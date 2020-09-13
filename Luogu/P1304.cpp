#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
	if(n<2) return false;
	if(n==2||n==3) return true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int n;
	int t;
	cin>>n;
	int num[(n/2)+1];
	for(int i=1;i<(n/2);i++)
	{
		num[i]=4+(i-1)*2;
	}
	for(int i=1;i<(n/2);i++)
	{
		for(int j=2;j<=(n/2);j++)
		{
			int f=0;
			if(prime(j))
			{
				t=num[i]-j;
				if(prime(t))
				{
					cout<<num[i]<<'='<<j<<'+'<<t<<endl;
					f=1;
				}
			}
			if(f==1) break;
		}
	}
	return 0;
}
