#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e3;

vector<int> E[maxn];

int n, m, d[maxn];
bool vis[maxn];
int root = 1;

void dfs(int u,int fa){
    vis[u] = true;
    for (int i = 0; i < E[u].size();i++){
        int v = E[u][i];
        if(v == fa)
            continue;
        d[v] = d[u] + 1;
        if(d[v]>d[m])
            m = v;
        if(!vis[v])
            dfs(v, u);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(root, 0), memset(vis, false, sizeof(vis));
    d[m] = 0, dfs(m, 0);
    printf("%d",d[m]);
    return 0;
}