#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,k,i=0;
	cin>>m>>k;
	if(m%19==0){
		while(m){	
			if((int)m%10==3){
		    i++;
			}
			m/=10;
		}
		if(i==k)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else cout<<"NO"<<endl;
	system("pause");
	return 0;
}
