#include <cstdio>

const int maxn = 32;
const int dx[5] = {0, -1, 0, 1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

int n;
int a[maxn][maxn];

void dfs(int x,int y){
    
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            scanf("%d", &a[i][j]);

    dfs(1, 1);

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            printf("%d", a[i][j]);
    return 0;
}