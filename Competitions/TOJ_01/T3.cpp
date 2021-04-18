#include <cstdio>

const int maxn = 13;
const int dx[5] = {0, -1, 0, 1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

int m, n, t, ans;
int sx, sy, fx, fy;
int a[maxn][maxn];
bool visit[maxn][maxn];

bool in_range(int x,int y){
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void dfs(int x,int y){
    visit[x][y] = true;
    if(x==fx&&y==fy)
        ans++;
    for (int i = 1; i <= 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(in_range(tx,ty)&&!a[tx][ty]&&!visit[tx][ty]){
            dfs(tx, ty);
            visit[tx][ty] = false;
        }
    }
}

int main()
{
    scanf("%d%d%d", &m, &n, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    for (int i = 1; i <= t;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    dfs(sx, sy);
    printf("%d", ans);
    return 0;
}