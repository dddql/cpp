#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

const int maxn = 5e5+10;
const int _maxlog = 19;

vector<int> T[maxn];

int n, m, root;
int fa[maxn][_maxlog], dep[maxn];
bool vis[maxn];

inline int read(){
    register int rslt = 0, o = 1, c = getchar();
    while(!isdigit(c)){
        o = c == '-' ? -1 : 1;
        c = getchar();
    }
    while(isdigit(c)){
        rslt = rslt * 10 + 'c' - '0';
        c = getchar();
    }
    return o * rslt;
}

void init(){
    int u, v;
    n = read(), m = read(), root = read();
    for (int i = 1; i < n;i++){
        u = read(), v = read();
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dep[root] = 1;
}

void getdepth(int u){
    vis[u] = true;
    for (int i = 0; i < T[u].size();i++){
        int v = T[u][i];
        if(!vis[v]){
            fa[v][0] = u;
            dep[v] = dep[u] + 1;
            getdepth(v);
        }
    }
}

void getfa(){
    for (int up = 1; (1 << up) <= n;up++)
        for (int i = 1; i <= n;i++)
            fa[i][up] = fa[fa[i][up - 1]][up - 1];
}

int LCA(int u,int v){
    if(dep[u]<dep[v])
        swap(u, v);

    int i = -1;
    while((1<<(i+1)) <= dep[u])
        ++i;

    for (int j = i; j >= 0;j--)
        if(dep[u]-dep[v]>=(1<<j))
            u = fa[u][j];

    if(u==v)
        return u;
    if(fa[u][0] == fa[v][0])
        return fa[u][0];

    for (int j = i; j >= 0;j--)
        if(fa[u][j]!=fa[v][j]){
            u = fa[u][j];
            v = fa[v][j];
        }

    return fa[u][0];
}

void query(){
    while(m--){
        int u, v, ans;
        u = read(), v = read();
        ans = LCA(u, v);
        printf("%d\n", ans);
    }
}

int main(){
    init();
    getdepth(root);
    getfa();
    query();
    return 0;
}