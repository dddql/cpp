#include<iostream>
#include<algorithm>
#define MAXN 1000100
using namespace std;

struct tree{
    long long sum,add,mul,l,r; 
    tree(){l = r = sum = add = 0;mul = 1;}
}t[4*MAXN+2];

long long a[MAXN],mod;

void build(long long p,long long x,long long y){
    t[p].l = x;t[p].r = y;
    if(x == y){
        t[p].sum = a[x]%mod;
        return;
    }
    long long mid = (x + y)>>1;
    build(p<<1,x,mid);
    build(p<<1|1,mid+1,y);
    t[p].sum = (t[p<<1].sum + t[p<<1|1].sum)%mod;
}

void spread(long long p){
    if(t[p].add == 0) return;
    long long pos = p << 1;
    t[pos].sum = (long long)(t[pos].sum*t[p].mul + (t[p].add*(t[pos].r - t[pos].l + 1))%mod)%mod;
    t[pos].add = (long long)(t[pos].add*t[p].mul+t[p].add)%mod; 
    t[pos].mul = (long long)t[pos].mul*t[p].mul%mod;
    pos |= 1;
    t[pos].sum = (long long)(t[pos].sum*t[p].mul + (t[p].add*(t[pos].r - t[pos].l + 1))%mod)%mod;
    t[pos].add = (long long)(t[pos].add*t[p].mul+t[p].add)%mod; 
    t[pos].mul = (long long)t[pos].mul*t[p].mul%mod;
    t[p].add = 0;t[p].mul = 1;
}

void add_num(long long p,long long a,long long x,long long y){
    if(x <= t[p].l && t[p].r <= y){
        t[p].add = (long long)(a+t[p].add)%mod;
        t[p].sum = (long long)(t[p].sum + a*(t[p].r - t[p].l + 1))%mod;
        return;
    }
    spread(p);
    t[p].sum = (t[p<<1].sum+t[p<<1|1].sum)%mod;
    long long mid = (t[p].l + t[p].r)>>1;
    if(x <= mid) add_num(p<<1,a,x,y);
    if(y > mid) add_num(p<<1|1,a,x,y);
    t[p].sum = (t[p<<1].sum+t[p<<1|1].sum)%mod;
}

void tms_num(long long p,long long a,long long x,long long y){
    if(x <= t[p].l && t[p].r <= y){
        t[p].sum = (long long)(t[p].sum*a)%mod;
        t[p].add = (long long)(t[p].add*a)%mod;
        t[p].mul = (long long)(t[p].mul*a)%mod;
        return;
    }
    spread(p);
    t[p].sum = (t[p<<1].sum+t[p<<1|1].sum)%mod;
    long long mid = (t[p].l + t[p].r)>>1;
    if(x <= mid) tms_num(p<<1,a,x,y);
    if(y > mid) tms_num(p<<1|1,a,x,y);
    t[p].sum = (t[p<<1].sum+t[p<<1|1].sum)%mod;
}

long long add_up(long long p,long long x,long long y){ 
    if(x <= t[p].l && t[p].r <= y) return t[p].sum;
    spread(p);
    long long mid = (t[p].l + t[p].r)>>1;
    long long ans = 0;
    if(x <= mid) ans = (ans+add_up(p<<1,x,y))%mod;
    if(y > mid) ans = (ans+add_up(p<<1|1,x,y))%mod;
    return ans;
}

int main(){
    long long n,m,k,x,y,z;
    freopen("P3373_2.in","r",stdin);
    freopen("1.out", "w", stdout);
    cin>>n>>m>>mod;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        cin>>k>>x>>y;
        if(k == 1){
            cin>>z;
            tms_num(1,z,x,y);
        }else if(k==3)
            cout<<add_up(1,x,y)<<endl;
        else{
            cin>>z;
            add_num(1,z,x,y);
        }
    }
    //fclose(FP);
    return 0;
}