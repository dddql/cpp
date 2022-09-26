#include <cstdio>

const int maxn = 5e5 + 10;

int n, m;
int a[maxn], c[maxn];

int lowbit(int x){
    return x & (-x);
}

void update_dot(int x,int y){
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

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]), update_dot(i, a[i]);
    for (int i = 1; i <= m;i++){
        int o, x, y;
        scanf("%d%d%d", &o, &x, &y);
        if(o==1)
            update_dot(x, y);
        else
            printf("%d\n", sum_seg(x, y));
    }
    return 0;
}