#include<bits/stdc++.h>
using namespace std;
int main(){
	float a,b,c,x1,x2,delta;
	cin>>a>>b>>c;
	delta=b*b-4*a*c;
	if(delta>0){
		x1=(-b+pow(delta,0.5))/2*a;
		x2=(-b-pow(delta,0.5))/2*a;
		cout<<setprecision(3)<<"x1="<<x1<<endl<<"x2="<<x2<<endl;
	}
	else if(delta==0){
		x1=(-b+pow(delta,0.5))/2*a;
		x2=x1;
		cout<<setprecision(3)<<"x1=x2="<<x1<<endl;
	}
	else{
		cout<<"无实数根"<<endl;
	}
	return 0;
}
