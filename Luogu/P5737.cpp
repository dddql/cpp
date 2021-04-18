#include <bits/stdc++.h>

using namespace std;

bool leap(int n)
{
	if(n%4==0&&n%100!=0) return true;
	if(n%100==0&&n%400==0) return true;
	return false;
}

int main()
{
	int x,y,n=0;
	cin>>x>>y;
	int year[y-x+1];
	for(int i=0;i<=(y-x);i++)
	{
		year[i]=x+i;
		if(leap(year[i])) n++;
	}
	cout<<n<<endl;
	for(int i=0;i<=(y-x);i++)
	{
		year[i]=x+i;
		if(leap(year[i])) cout<<year[i]<<" ";
	}
	return 0;
}
