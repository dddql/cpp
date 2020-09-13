#include<bits/stdc++.h> 
using namespace std;
int main(){
	int i,a=0,b=0,c=0;
	char n;
	for(i=1;i<=25;i++){
		cin>>n;
		switch(n){
			case 'a':a++;break;
			case 'b':b++;break;
			case 'c':c++;break;
			default:break;
		}
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<endl;
	return 0;
}
