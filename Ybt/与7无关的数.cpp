#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s=0;
	int i,t;
	bool b;
	cin>>n;
	for(i=1;i<=n;i++){
		t=i;
		b=1;
		while(t){
			if(t%10==7||t%7==0){
				b=0;
				break;
			}
			else t/=10;
		}
		if(b)s=s+i*i;
	}
	cout<<s<<endl;
	return 0;
}
