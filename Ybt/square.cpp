#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,d;
	char e,c;
	int i,j;
	scanf("%d%d%s%d",&a,&b,&c,&d);
	if(d) e=c;
	else e=' ';
	for(i=1;i<=a;i++){
	    for(j=1;j<=b;j++){
			if(j==1||j==b||i==1||i==a)printf("%c",c);
			else printf("%c",e);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
