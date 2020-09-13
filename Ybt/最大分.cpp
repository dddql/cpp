#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,score,maxs=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>score;
		maxs=maxs<score?score:maxs;
	}
	cout<<maxs<<endl;
	system("pause");
	return 0;
}
