#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	for(x=0;x<=20;x++){
		for(y=0;y<=33;y++){
			z=100-x-y;
			if(5*x+3*y+z/3==100&&z%3==0)
			    cout<<x<<" "<<y<<" "<<z<<endl;
	    }
	}
	system("pause");
	return 0;
}
