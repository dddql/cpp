#include <cstdio>

const int maxn = 10000;

int value[maxn], win[maxn], n;

void dfs(int p){
    if(p>=1<<n)
        return;

    int ls = p << 1, rs = p << 1 | 1;

    dfs(ls);
    dfs(rs);

    int lv = value[ls], rv = value[rs];

    if(lv>rv){
        value[p] = lv;
        win[p] = win[ls];
    }else{
        value[p] = rv;
        win[p] = win[rs];
    }

}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 1 << n;i++){
        scanf("%d", &value[i + (1 << n)]);
        win[i + (1 << n)] = i + 1;
    }
    dfs(1);
    int ans = value[2] > value[3] ? win[3] : win[2];
    printf("%d", ans);
    return 0;
}