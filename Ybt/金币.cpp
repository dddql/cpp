#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j,d=0,s=0;
	cin>>n;
	for(i=1;;i++){
		for(j=1;j<=i;j++){
			d++;
		    s=s+i;
		    if(d==n){
			    cout<<s<<endl;
			    return 0;
		    } 
		}
	}
	return 0;
}
