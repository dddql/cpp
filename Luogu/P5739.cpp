#include<bits/stdc++.h>

using namespace std;

int factorial(int n)
{
	int ans=1,i=1;
	loop:
	if(i<=n)
	{
		ans*=i;
		i++;
	}
	else return ans;
	goto loop;
}
int main(){
	int n;
	
	cin>>n;
	cout<<factorial(n)<<endl;
	
	return 0;
}
