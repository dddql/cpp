#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,t,s;
	for(x=100;x<=999;x++){
		t=x;
		s=0;
		while(t!=0){
			s+=pow(t%10,3);
			t/=10;
		}
		if(x==s)cout<<x<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
