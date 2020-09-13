#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,s,t;
	for(a=1;a<=9;a++){
		for(b=0;b<=9;b++){
			s=a*1100+b*11;
			t=sqrt(s);
			if(s==t*t)cout<<s<<" "<<t<<endl;
		}
	}
	system("pause");
	return 0;
}
