#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,a=1,b=1,ans=0;
	cin>>k;
	cout<<a<<"\t"<<b<<"\t"; 
	for(int i=3;i<=k;i++){
		ans=a+b;
		a=b;
		b=ans;
		cout<<ans<<"\t";
		if(i%7==0)cout<<endl;
	}
	return 0;
}
