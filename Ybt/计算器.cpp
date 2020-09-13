#include<bits/stdc++.h>
using namespace std;
int main(){
	float x,y;
	char op;
	cin>>x>>op>>y;
	switch(op){
		case '+':
			cout<<x+y<<endl;
			break;
		case '-':
			cout<<x-y<<endl;
			break;
		case '*':
		    cout<<x*y<<endl;
		    break;
		case '/':
			if(y==0)
			    cout<<"divided by zero!";
			else    
			    cout<<x/y<<endl;
			break;
		case '%':
			if(y==0)
			    cout<<"divided by zero!";
			else
			    cout<<(int)x%(int)y<<endl;
			break;
		case '^':
			cout<<pow(x,y)<<endl;
			break;
		case '&':
			if((x>0)+(y>0)!=2)
			    cout<<"below zero!";
		    else 
			    cout<<log(y)/log(x)<<endl;							
	}
	return 0;
}
