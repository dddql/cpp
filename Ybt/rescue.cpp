#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,p;
	double x,y,d,ans=0;
	cin>>n;
	while(n--){
		cin>>x>>y>>p;
		d=sqrt(x*x+y*y);
		ans+=2*d/50+(1+0.5)*p;
	}
	cout<<ceil(ans)<<endl;
	system("pause");
	return 0;
}
