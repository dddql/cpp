#include<bits/stdc++.h>
using namespace std;
const int M=1000000; 
int main(){
	int n;
	int f,s=0;
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		f=1;
		for(j=1;j<=i;j++){
			f*=j;
		}
		s=s+f%M;
	}
	printf("%d",s%M);
	return 0;
}
