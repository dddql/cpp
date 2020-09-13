#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
	int n;
	float c=0,max1=0,N[301]={},max=0,min=10000,t=0,C[301]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N[i];
		max=max<N[i]?N[i]:max;
		min=min>N[i]?N[i]:min;
	}
	for(int i=1;i<=n;i++){
		if(N[i]!=max&&N[i]!=min){
			t+=N[i];
		}
	}
	c=1.0*t/(n-2);
	for(int i=1;i<=n;i++){
		if(N[i]!=max&&N[i]!=min){
		    if(N[i]>=c)C[i]=N[i]-c;
		    else C[i]=c-N[i];
		    max1=max1<C[i]?C[i]:max1;
		}
	}
	cout<<fixed<<setprecision(2)<<c<<" "<<max1;
	return 0;
}
