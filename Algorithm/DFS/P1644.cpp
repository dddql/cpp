#include <cstdio>

int n, m, ans = 0;
const int dx[4] = {1, 2, 2, 1};
const int dy[4] = {2, 1, -1, -2};

void dfs(int x,int y){
    if(x==m&&y==n){
        ans++;
        return;
    }
    for (int i = 0; i < 4;i++)
        if(x + dx[i] <= m && y + dy[i] >= 0 && y + dy[i] <= n)
            dfs(x + dx[i], y + dy[i]);
}

int main()
{
    scanf("%d%d", &n, &m);
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}