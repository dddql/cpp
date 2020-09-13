#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,sum=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		if(i%17==0){
		    sum+=i;
		    i+=16;
		}
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}
