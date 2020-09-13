#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=7;
	int m,n,k;
	int flag;
	cin>>m>>n>>k;
	do{
		x+=1;
		flag=1;
		if(x%3!=m){flag=0;continue;}
		if(x%5!=n){flag=0;continue;}
		if(x%7!=k){flag=0;continue;}
	}while(flag!=1);
	cout<<x<<endl;
	return 0;
}
