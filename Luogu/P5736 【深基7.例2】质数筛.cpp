#include<bits/stdc++.h>

using namespace std;
 
bool is_prime(int n)
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
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if(is_prime(num[i]))
			cout<<num[i]<<" ";
	}
	return 0;
}
