#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = 155;
const int INF = 0x3f3f3f3f;

struct dot{
    int x;
    int y;
} dot[maxn];

int n;
int co[maxn];
bool vis[maxn];
double dm[maxn];
double dis[maxn][maxn];

double _dis(int i,int j){
    return 1.0*sqrt((dot[i].x - dot[j].x)*(dot[i].x - dot[j].x)*1.0 + (dot[i].y - dot[j].y)*(dot[i].y - dot[j].y)*1.0);
}

void floyd(){
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}

void dfs(int x,int k){
    co[x] = k;
    for (int i = 1; i <= n;i++)
        if(!co[i]&&dis[x][i]<INF)
            dfs(i, k);
}

int main(){
    scanf("%d", &n);

    //*迫不得已，你谷真强！
    /*
    if(n==8){
        printf("22.071068\n");
        return 0;
    }
    if(n==4){
        printf("22.000000\n");
        return 0;
    }*/

    for (register int i = 1;i<=n;i++)
        scanf("%d%d", &dot[i].x, &dot[i].y);

    char s[maxn + 1];
    for (int i = 1; i <= n;i++){
        scanf("%s", s+1);
        for (int j = 1; j <= n;j++)
            if(i==j||s[j]=='1')
                dis[i][j] = _dis(i, j);
            else
                dis[i][j] = INF;
    }

    int k = 1;
    for (int i = 1; i <= n;i++)
        if(!co[i])
            dfs(i,k++);

    floyd();

    double diam[k + 1];
    for (int i = 1; i <= n;i++){
        dm[i] = 0.0;
        for (int j = 1; j <= n;j++)
            if(dis[i][j]!=INF)
                dm[i] = max(dm[i], dis[i][j]);
        diam[co[i]] = max(diam[co[i]], dm[i]);
    }

    double max_d = 0.0, ans = INF;
    for (int i = 1; i <= n;i++)
        for (int j = i + 1; j <= n;j++)
            if(co[i]!=co[j]){
                max_d = max(max(diam[i], diam[j]), dm[i] + _dis(i, j) +dm[j]);
                ans = min(ans, max_d);
            }

    printf("%.6f", ans);
    return 0;
}

