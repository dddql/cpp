#include<bits/stdc++.h>
using namespace std;
#define FL(a) {freopen(a".in","r",stdin);freopen(a".out","w",stdout);}
#define Mod 998244353
#define int long long
const int mx=200000;
int n,a,tax[200005],sum[200005];
const int inv2=(Mod+1)/2,inv3=(Mod+1)/3,inv6=inv2*inv3%Mod;

signed main(){
//	FL("data1-1");
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a);
		tax[a]++;
	}
	int ans=0;
	for(int i=1;i<=mx;++i)sum[i]=(sum[i-1]+tax[i])%Mod;
	for(int i=1;i<=mx;++i){
		int N=tax[i];
		if(N<2)continue;
//		cerr<<"N: "<<N<<endl;
		ans=(ans+N*(N-1)/2%Mod*(sum[min(i*2-1,mx)]-N)%Mod+N*(N-1)%Mod*(N-2)%Mod*inv6%Mod)%Mod;
	}
	printf("%lld\n",ans);
	cerr<<"ans: "<<ans<<endl;
	return 0;
}

