#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,m,n,num,ans=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>num;
		if(num==n)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
