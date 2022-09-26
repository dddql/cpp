//!区间修改，单点查询
//!考虑建立差分数组，并对其建立树状数组

#include <cstdio>

const int maxn = 5e5 + 10;

int n, m;
long long a[maxn], b[maxn], c[maxn];

int lowbit(int x){
    return x & (-x);
}

void update_dot(int x,long long y){
    for (; x <= n;x+=lowbit(x))
        c[x] += y;
}

int sum(int x){     //查询前缀和
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += c[x];
    return ans;
}

int sum_seg(int x,int y){
    if(x == 1)
        return sum(y);
    else
        return sum(y) - sum(x - 1);
}

void update_seg(int x,int y,long long k){
    b[x] += k, b[y + 1] -= k;
    update_dot(x, k);
    update_dot(y + 1, -k);
}

long long query(int x){
    long long ans = 0;
    for (; x;x-=lowbit(x))
        ans += c[x];
    return ans;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i - 1];
        update_dot(i, b[i]);
    }
    for (int i = 1; i <= m;i++){
        int o = 0;
        scanf("%d", &o);
        if(o==1){
            long long x, y, k;
            scanf("%lld%lld%lld", &x, &y, &k);
            update_seg(x, y, k);
        }
        else{
            int x;
            scanf("%d", &x);
            printf("%d\n",query(x));
        }
    }
    return 0;
}
/*
1 5 4 2 3       1 4 -1 -2 1
1 7 6 4 3       1 6 -1 -2 -1
6
0 6 5 3 2       0 6 -1 -2 -1
0 6 12 10 9     0 6 6 -2 -1
10
*/