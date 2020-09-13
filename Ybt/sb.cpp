#include<iostream>
using namespace std;
int main(){
	int a,b,c,d=0;
	cin>>a;
	for(b=1;b<=a;b++){
		cin>>c;
		d+=c;
	}
	float e=d/a;
	cout<<e<<endl;
	return 0;
}               
