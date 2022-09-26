#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e3+10;
const int _maxlog = 16;

vector<int> T[maxn];

int n, _max;
int x, y, l;
int d[maxn], dep[maxn], fa[maxn][_maxlog];
bool vis[maxn];

void dfs(int u,int fa){
    vis[u] = true;
    for (int i = 0; i < T[u].size();i++){
        int v = T[u][i];
        if(v==fa)
            continue;
        d[v] = d[u] + 1;
        if(d[v]>d[_max])
            _max = v;
        if(!vis[v])
            dfs(v, u);
    }
}

void getDiam(){
    dfs(1, 0);
    memset(vis, false, sizeof(vis));
    x = _max;
    dfs(_max, 0);
    y = _max;
}

void getDepth_dfs(int u){
    vis[u] = true;
    for (int i = 0; i < T[u].size();i++){
        int v = T[u][i];
        if(!vis[v]){
            fa[v][0] = u;
            dep[v] = dep[u] + 1;
            getDepth_dfs(v);
        }
    }
}

void getParents(){
    for (int up = 1; (1 << up) <= n;up++)
        for (int i = 1; i <= n;i++)
            fa[i][up] = fa[fa[i][up - 1]][up - 1];
}

int LCA(int u,int v){
    if(dep[u] < dep[v]) // 使满足u深度更大, 便于后面操作
        swap(u, v);

    // i求的是最多能向上跳2的几次幂步 
    int i = -1;
    while((1<<(i+1)) <= dep[u])
        ++i;

    // 平衡深度
    for (int j = i; j >= 0;j--)
        if(dep[u]-(1<<j)>=dep[v])
            u = fa[j][u];

    //特判刚好跳到一起（u，v有直接的祖宗关系）
    if(u==v)
        return u;

    // u和v一起向上跳
    for (int j = i; j >= 0;j--)
        if(fa[j][u]!=fa[j][v]){
            u = fa[j][u];
            v = fa[j][v];
        }

    //此时u已经位于LCA的子结点
    return fa[0][u];
}

void getLCA(int x,int y){
    memset(vis, false, sizeof(vis));
    getDepth_dfs(1);
    getParents();
    l = LCA(x, y);
}

int getcentr(int x,int y,int l){
    int len = dep[x] + dep[y] - 2 * dep[l];
    if(dep[x]-dep[l]>len/2){
        for (int i = 1; i <= len / 2;i++)
            x = fa[x][0];
        return x;
    }
    for (int i = 1; i <= len - len / 2;i++)
        y = fa[y][0];
    return y;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        T[u].push_back(v), T[v].push_back(u);
    }
    getDiam();
    getLCA(x,y);
    printf("%d", getcentr(x,y,l));
    return 0;
}