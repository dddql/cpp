#include<bits/stdc++.h>
using namespace std;
int main(){
	int i=1,j;
	while(i<=9){
		j=1;
		while(j<=i){
			cout<<j<<'*'<<i<<'='<<i*j<<"\t";
			j++;
		}
		i++;
		cout<<endl;
	}
	system("pause");
	return 0;
}
