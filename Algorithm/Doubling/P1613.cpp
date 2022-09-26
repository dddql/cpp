#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int maxn = 55;
const int max_log = 64;

std::vector<int> e[maxn];

int n, m;
int dis[maxn][maxn];
bool f[maxn][maxn][max_log + 1];

void check(){
    for (int t = 1; t <= max_log;t++)
        for (int i = 1; i <= n;i++)
            for (int k = 1; k <= n;k++)
                for (int j = 1; j <= n;j++)
                    if(f[i][k][t - 1] && f[k][j][t - 1])
                        f[i][j][t] = true, dis[i][j] = 1;
}

void floyd(){
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main(){
    scanf("%d%d", &n, &m);

    //!凡涉及最短路，都应记得初始化dis为INF
    std::memset(dis, 0x3f, sizeof(dis));
    
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        dis[u][v] = 1;
        f[u][v][0] = true;
    }
    check();
    floyd();
    printf("%d", dis[1][n]);
    return 0;
}