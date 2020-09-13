#include <bits/stdc++.h>
#define MAXN 2001
using namespace std;

struct nums{
	int arg[5005],len;
	nums(){
		memset(arg,0,sizeof(arg));
		len = 1;
	}
	
	void print(){
		for(int i = len-1;i >= 0;i--)
			cout<<arg[i];
		cout<<endl;
	}
	
	void scan(){
		char s[5005];
		cin>>s;
		*this = s;
	}
	
	void cleanZero(){
		while(arg[len - 1] == 0&&len>1) len--;//这里的len>1是保证至少有一位 
	}
	
	nums operator=(char *s){
		nums a;
		a.len = strlen(s);
		for(int i = 0;i < a.len;i++)
			a.arg[i] = s[a.len - i - 1] - '0';//倒着读入，也就是说arg[0]就是个位，arg[len-1]是最高位 
		a.cleanZero();
		*this = a;
		return *this;
	}
	
	nums operator=(int a){
		char s[5005];
		sprintf(s,"%d",a);
		*this = s;
		return *this;
	}
	
	nums operator+(nums a){
		nums sum;	
		int x = 0,l = max(len,a.len);//求出位数 
		
		for(int i = 0;i < l;i++){
			x = a.arg[i]+arg[i]+sum.arg[i];
			sum.arg[i] = x%10;
			sum.arg[i+1] = x/10;
		}
		
		sum.len = l;
		if(sum.arg[sum.len] > 0) sum.len++;//如果最高位进位了就再加一 
		return sum;
	} 
	
	nums operator+(int a){
		nums b;
		b = a;
		return (*this+b);
	}
	
	nums operator-(nums a){
		nums dif;
		int x,l = max(len,a.len);
		for(int i = 0;i < l;i++){
			x = arg[i] - a.arg[i] - dif.arg[i];
			if(x < 0){
				dif.arg[i] = 10+x;
				dif.arg[i+1] = 1;
			}else{
				dif.arg[i] = x;
			}
		}
		dif.len = l;
		dif.cleanZero();
		return dif;
	}
	
	nums operator-(int a){
		nums b;
		b = a;
		return (*this-b);
	}
	
	nums operator*(nums a){
		nums prod,tmp;
		int x,g = 0;
		for(int i = 0;i < a.len;i++){
			tmp = 0;
			g = 0;
			for(int j = 0;j < len;j++){
				x = arg[j]*a.arg[i] + tmp.arg[i+j];
				tmp.arg[i+j] = x%10;
				tmp.arg[i+j+1] = x/10;
			}
			tmp.len = (tmp.arg[len+i]>0)?(len+i+1):len+i;
			prod = prod + tmp;
		}
		prod.cleanZero();
		return prod;
	}
	
	nums operator*(int a){
		nums b;
		b = a;
		return (*this*b);
	}
	
	nums operator/(int a){
		nums quo;
		int x = 0;
		for(int i = len-1;i >= 0;i--){
			x = x*10 + arg[i];
			quo.arg[i] = x/a;
			x = x%a; 
		}
		quo.len = len;
		quo.cleanZero();
		return quo;
	}
	
	bool operator<(nums a){
		if(len > a.len) return false;
		else if(len < a.len) return true;//判断位数 
		
		for(int i = a.len-1;i >= 0;i--){
			if(arg[i] > a.arg[i]) return false;
			else if(arg[i] < a.arg[i]) return true;
		}//判断每位大小
		 
		return false;//判断相等 
	}
	
	bool operator<(int a){
		nums b;
		b = a;
		return (*this<b);
	}
	
	bool operator<=(nums a){
		if(len > a.len) return false;
		else if(len < a.len) return true;//判断位数 
		
		for(int i = a.len-1;i >= 0;i--){
			if(arg[i] > a.arg[i]) return false;
			else if(arg[i] < a.arg[i]) return true;
		}//判断每位大小
		 
		return true;//判断相等 
	}
	
	bool operator<=(int a){
		nums b;
		b = a;
		return (*this<=b);
	}
	
	bool operator==(nums a){
		if(len != a.len) return false;
		
		for(int i = a.len-1;i >= 0;i--)
			if(arg[i] != a.arg[i]) return false;
			
		return true; 
	}
	
	bool operator==(int a){
		nums b;
		b = a;
		return (*this==b);
	}
};

int main(){

	return 0;
}
