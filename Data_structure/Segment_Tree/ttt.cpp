#include <cstdio>
#define maxn 100010
using namespace std;

typedef long long LL;
LL n, m;
LL a[maxn], d[maxn << 2], b[maxn << 2];
LL ans[maxn], k;

void build(LL s,LL t,LL p){
    if(s==t){
        d[p] = a[s];
        return;
    }
    LL mid = (s + t) >> 1;
    build(s, mid, p << 1);
    build(mid + 1, t, p << 1 | 1);
    push_up(p);
}

void push_up(LL p){
    d[p] = d[p << 1] + d[p << 1 | 1];
}

void push_down(LL p){
    d[p << 1] += (mid - s + 1) * b[p];
    d[p << 1 | 1] += (t - mid) * b[p];
    b[p << 1] += b[p];
    b[p << 1 | 1] += b[p];
    b[p] = 0;
}

LL getsum(LL l,LL r,LL s,LL t,LL p){
    if(s>=l&&t<=r)
        return d[p];
    LL mid = (s + t) >> 1;
    LL sum = 0;
    if(b[p])
        push_down(p);
    if(l<=mid)
        sum += getsum(l, r, s, mid, p << 1);
    if(mid<r)
        sum += getsum(l, r, mid + 1, t, p << 1 | 1);
    return sum;
}

void update(LL l,LL r,LL c,LL s,LL t,LL p){
    if(s>=l&&t<=r){
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }
    LL mid = (s + t) >> 1;
    if(b[p])
        push_down(p);
    if(l<=m)
        update(l, r, c, s, mid, p << 1);
    if(r>m)
        update(l, r, c, mid + 1, t, p << 1 | 1);
    
}