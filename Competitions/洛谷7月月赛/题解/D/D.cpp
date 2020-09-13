#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT __int128
#define ULL unsigned long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int MUL(int a,int x,int Mod){
//	return (INT)a*x%Mod;
	int ans=0,w=a;
	while(x){
		if(x&1)ans=(ans+w)%Mod;
		w=(w+w)%Mod;
		x>>=1;
	}
	return ans;
}
const int G1=1145141;
const int MMod=1000000000000000003ll;
#define MN 2000005
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
#define piii pair<int,int>
#define mp make_pair
#define x first
#define y second
int aupd(int a){return (a<MMod)?a:(a-MMod);}
int supd(int a){return (a>=0)?a:(a+MMod);}
int pw1[MN],s1[MN];
int sum[MN];
int n,q,a[MN];
void build(){
	for(int i=1;i<=n;++i){
		s1[i]=aupd(s1[i]+pw1[a[i]]);
		sum[i]=sum[i]+a[i];
		int to=i+(i&(-i));
		s1[to]=aupd(s1[to]+s1[i]);
		sum[to]=sum[to]+sum[i];
	}
}
void add(int x,int v1,int v2){
	while(x<=n){
		s1[x]=aupd(s1[x]+v1);
		sum[x]+=v2;x+=x&(-x);
	}
}
piii ask(int x){
	piii res=mp(0,0);
	while(x){
		res.x=aupd(res.x+s1[x]);
		res.y+=sum[x];
		x-=x&(-x);
	}
	return res;
}
piii qry(int l,int r){
	piii R=ask(r),L=ask(l-1);
	R.x=supd(R.x-L.x);
	R.y-=L.y;
	return R;
}
signed main(){
	n=read();q=read();
	pw1[0]=1;
	for(int i=1;i<=1000000;++i){
		pw1[i]=MUL(pw1[i-1],G1,MMod);
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build();
	for(int i=1;i<=q;++i){
		int op=read();
		if(!op){
			int x=read(),y=read();
			add(x,supd(pw1[y]-pw1[a[x]]),y-a[x]);
			a[x]=y;
		}
		else{
			int l1=read(),r1=read(),l2=read(),r2=read(),len=r1-l1+1;
			piii res1=qry(l1,r1),res2=qry(l2,r2);
			int k=res2.y-res1.y;
			if(abs(k)%len!=0){puts("NO");continue;}
			k/=len;
			if(k>=0){
				res1.x=MUL(res1.x,pw1[k],MMod);
			}
			else {
				k=-k;
				res2.x=MUL(res2.x,pw1[k],MMod);
			}
			if(res1.x==res2.x)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}


