#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,i,num,s1=0,s5=0,s10=0;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>num;
		switch(num){
			case 1:s1++;break;
			case 5:s5++;break;
			case 10:s10++;break;
		}
	}
	cout<<s1<<endl;
	cout<<s5<<endl;
	cout<<s10<<endl;
	system("pause"); 
	return 0;
}
