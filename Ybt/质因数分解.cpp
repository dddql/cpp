#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i=2;
	bool first=1;
	cin>>n;
	cout<<n<<'=';
	while(n!=1){
		while(n%i==0){
			if(first){
				cout<<i;
				first=0;
			}
			else cout<<'*'<<i;
			n/=i;
		}
		i++;
	}
	cout<<endl;
	return 0;
}
