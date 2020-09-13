#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,min=101,max=-1,t=0,sum=0;
	float avg;
	cin>>x;
	while(cin>>x){
		if(max<x)max=x;
		if(min>x)min=x;
		t++;
		sum+=x;
	}
	sum=sum-max-min;
	avg=(float)sum/(t-2);
	cout<<min<<" "<<max<<" "<<avg<<t<<endl;
	system("pause"); 
	return 0;
}

