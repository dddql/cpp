#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,i;
	for(x=100;x<=200;x++){
		int t=sqrt(x);
		for(i=2;i<=t;i++){
			if(x%i==0)break;
		}
		if(i>t)cout<<x<<endl;
	}
	system("pause");
	return 0;    
}
