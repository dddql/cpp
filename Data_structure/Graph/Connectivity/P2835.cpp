#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10;

vector<int> e_1[maxn];
vector<int> e_2[maxn];

int n, m, t, num = 1;
int ext[maxn], co[maxn];
bool vis[maxn];

void add_edge(int u,int v){
    e_1[u].push_back(v);
    e_2[v].push_back(u);
}

void dfs_1(int x){
    vis[x] = true;
    for (int i = 0; i < e_1[x].size();i++)
        if(!vis[e_1[x][i]])
            dfs_1(e_1[x][i]);
    ext[++t] = x;
}

void dfs_2(int x){
    co[x] = num;
    vis[x] = true;
    printf("%d ", x);
    for (int i = 0; i < e_2[x].size();i++)
        if(!vis[e_2[x][i]])
            dfs_2(e_2[x][i]);
}

void kosaraju(){
    for (int i = 1; i <= n;i++)
        if(!vis[i])
            dfs_1(i);

    memset(vis, 0, sizeof(vis));

    for (int i = t; i >= 1;i--){
        if(!vis[i]){
            dfs_2(ext[i]);
            printf("\n");
        }
        num++;
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        int t;
        scanf("%d", &t);
        while(t!=0){
            add_edge(i, t);
            scanf("%d", &t);
        }
    }

    kosaraju();

    for(int i = 1)
    return 0;
}