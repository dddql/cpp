#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=0,n=0,x,ans;
	for(int i=1;i<=12;i++){
		cin>>x;
		t+=300-x;
		if(t<0){
			cout<<-i<<endl;
			system("pause");
			return 0;
		}
		if(t>=100){
			n+=t/100;
			t%=100;
		}
	}
	ans=n*120+t;
	cout<<ans<<endl;
	system("pause");
	return 0;
}
