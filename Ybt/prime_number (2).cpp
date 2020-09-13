#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,i;
	scanf("%d",&x);
	for(i=2;i<=x-1;i++){
		if(x%i==0)break;
	}
	if(i<x)cout<<"no"<<endl;
	else cout<<"yes"<<endl;
	return 0;
}
