//todo
#include <cstdio>
#include <algorithm>
#define maxn 200050
typedef long long LL;
using namespace std;

LL n;
LL a[maxn];

struct node{
    LL lsum, rsum, ssum;
} d[maxn << 2];

LL ls(LL p){          //*左儿子
    return p << 1;
}

LL rs(LL p){          //*右儿子
    return p << 1 | 1;
}

void push_up(LL p){        //*上传
    d[p].lsum = max(d[ls(p)].lsum, d[ls(p)].ssum + d[rs(p)].lsum);
    d[p].rsum = max(d[rs(p)].rsum, d[rs(p)].ssum + d[ls(p)].rsum);
    d[p].ssum = max(max(d[ls(p)].ssum, d[rs(p)].ssum), d[ls(p)].rsum + d[rs(p)].lsum);
}

void build(LL s,LL t,LL p){      //*建树
    if(s==t){
        d[p].lsum = d[p].rsum = d[p].ssum = a[s];
        return;
    }
    LL mid = (s + t) >> 1;
    build(s, mid, ls(p));
    build(mid + 1, t, rs(p));
    push_up(p);
}

int main()
{
    scanf("%lld", &n);
    LL max = -20000;
    for (LL i = 1; i <= n;i++){
        scanf("%lld", &a[i]);
        if(a[i]>max)
            max = a[i];
    }

    build(1, n, 1);
    /*
    LL t = 0, sum = 0;
    if(max<0){
        printf("%d", max);
        return 0;
    }
    for (LL i = 1; i <= n; i++){
        t += a[i];
        if(t<0)
            t = 0;
        else if(t>sum)
            sum = t;
    }*/

    printf("%lld", d[1].ssum);
    //printf("%d", sum);
    return 0;
}