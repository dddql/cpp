#include<bits/stdc++.h>
using namespace std;
int seq(int x,int n)
{
	if(x==n) return 1;
	return 2*(seq(x+1,n)+1);
}

int main(){
	int n;
	cin>>n;
	cout<<seq(1,n)<<endl;
	return 0;
}
