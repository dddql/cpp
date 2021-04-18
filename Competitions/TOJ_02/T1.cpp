#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 102;
const int dx[5] = {0, -1, 0, 1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

int r, c;
int ans = -1;
int a[maxn][maxn], m[maxn][maxn];
bool visit[maxn][maxn];

bool is_biggest(int x,int y){
    bool flag = true;
    for (int i = 1; i <= 4;i++)
        if(a[x][y]<a[x+dx[i]][y+dy[i]])
            flag = false;
    return flag;
}

int dfs(int x,int y){
    if(m[x][y])
        return m[x][y];

    if(is_biggest(x,y))
        return m[x][y] = 1;

    for (int i = 1; i <= 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(a[x][y]<a[tx][ty]&&!visit[x][y]){
            visit[x][y] = true;
            m[x][y] = max(dfs(tx, ty) + 1, m[x][y]);
            visit[x][y] = false;
        }
    }

    return m[x][y];
}

int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r;i++)
        for (int j = 1; j <= c;j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= r;i++)
        for (int j = 1; j <= c;j++)
            ans = max(dfs(i,j), ans);

    printf("%d", ans);
    return 0;
}