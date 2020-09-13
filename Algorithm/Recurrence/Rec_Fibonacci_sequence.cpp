#include<bits/stdc++.h>
using namespace std;

int fib(int x)
{
	if(x==1||x==2) return 1;
	return fib(x-1)+fib(x-2);
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cout<<fib(i)<<" ";
	return 0;
}
