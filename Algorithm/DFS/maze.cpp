#include <cstdio>

int map[10][10];
int m, n, ans;

int dfs(int x,int y){
    if(x+y>a+b){
        return;
    }
    
}

void init(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            scanf("%d", &map[i][j]);
    scanf("%d%d", &x, &y);
    scanf("%d%d", &a, &b);
}

int main()
{
    init();

    dfs(x, y);

    printf("%d", ans);

    return 0;
}