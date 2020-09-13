#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	cin>>a;
	while(a-1){
		if(a%2==0){
		cout<<a<<'/'<<2<<'='<<a/2<<endl;
		a/=2;
		int b=a/2;
		if(b==1){
		cout<<a<<'/'<<2<<'='<<a/2<<endl;
		cout<<"End"<<endl;
		return 0;
		}
		}
		if(a%2==1){
		cout<<a<<'*'<<3<<'+'<<1<<'='<<a*3+1<<endl;
		a=a*3+1;
		}
	}
	return 0;
}
