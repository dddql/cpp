#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e6+10;
int sum[M*2],n,k,maxn,ans=-1;

signed main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		sum[a]+=b,maxn=max(maxn,a);
	}
	if (k==0)
	{
		for (int i=0;i<=maxn;i++)
			if (sum[i]!=1&&sum[i])
				ans=max(ans,i*sum[i]);
		if (ans==-1)cout<<"NO";
		else cout<<ans;
		return 0;
	}
	for (int i=0;i<=maxn;i++)
	{
		int j=i+k;
		if (sum[i]&&sum[j])
			ans=max(ans,min(sum[i],sum[j])*(i+j));
	}
	if (ans==-1)cout<<"NO";
	else cout<<ans;
	return 0;
}