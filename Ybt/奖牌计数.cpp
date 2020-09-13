#include<bits/stdc++.h>
using namespace std;
int main(){
	int day,g,s,c,tg=0,ts=0,tc=0,t=0;
	cin>>day;
	for(int i=1;i<=17;i++){
		cin>>g>>s>>c;
		tg+=g;
		ts+=s;
		tc+=c;
		t+=g+s+c;
	}
	cout<<tg<<" "<<ts<<" "<<tc<<" "<<t<<endl;
	return 0;
}
