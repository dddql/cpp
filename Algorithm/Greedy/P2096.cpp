#include <cstdio>
#include <algorithm>
#define maxn 20010
using namespace std;

int m, n;
int a[105][maxn];
int r[maxn];

/*
struct node{
    int data;
    int lsum, rsum, ssum;
} d[maxn << 2];

int ls(int p){          //*左儿子
    return p << 1;
}

int rs(int p){          //*右儿子
    return p << 1 | 1;
}

void push_up(int p){        //*上传
    d[p].data += d[ls(p)].data + d[rs(p)].data;
    d[p].lsum = max(d[ls(p)].lsum, d[ls(p)].ssum + d[rs(p)].lsum);
    d[p].rsum = max(d[rs(p)].rsum, d[rs(p)].ssum + d[ls(p)].rsum);
    d[p].ssum = max(max(d[ls(p)].ssum, d[rs(p)].ssum), d[ls(p)].rsum + d[rs(p)].lsum);
}

void build(int s,int t,int p){      //*建树
    if(s==t){
        d[p].data = r[s];
        d[p].lsum = d[p].rsum = d[p].ssum = r[s];
        return;
    }
    int mid = (s + t) >> 1;
    build(s, mid, ls(p));
    build(mid + 1, t, rs(p));
    push_up(p);
}*/

int main()
{
    //freopen("travel8.in", "r", stdin);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            scanf("%d", &a[i][j]);
    for (int j = 1; j <= n;j++){
        int temp = -200;
        for (int i = 1; i <= m;i++){
            if(a[i][j]>temp)
                temp = a[i][j];
        }
        r[j] = temp;
    }

    //build(1, n, 1);
    int t = 0, sum = 0;
    for (int i = 1; i <= n; i++){
        t += r[i];
        if(t<0)
            t = 0;
        else if(t>sum)
            sum = t;
    }
    //printf("%d", d[1].ssum);
    printf("%d", sum);
    return 0;
}