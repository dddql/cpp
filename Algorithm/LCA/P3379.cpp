//*倍增求LCA
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

const int maxn = 5e5+10;

vector<int> T[maxn];

int n, m, root;
int parents[18][maxn], depth[maxn];
bool visited[maxn];

inline int read(){
    register int rslt = 0, b = 1, c = getchar();
    while(!isdigit(c)){
        b = c == '-' ? -1 : 1;
        c = getchar();
    }
    while(isdigit(c)){
        rslt = rslt * 10 + c - '0';
        c = getchar();
    }
    return b * rslt;
}

void init(){
    int u, v;
    n = read(), m = read(), root = read();
    for (int i = 1; i < n;i++){
        u = read(), v = read();
        T[u].push_back(v);
        T[v].push_back(u);
    }
    depth[root] = 1;
}

void getDepth_dfs(int u){
    visited[u] = true;
    for (int i = 0; i < T[u].size();i++){
        int v = T[u][i];
        if(!visited[v]){
            parents[0][v] = u;
            depth[v] = depth[u] + 1;
            getDepth_dfs(v);
        }
    }
}

void getParents(){
    for (int up = 1; (1 << up) <= n; up++)
        for (int i = 1; i <= n; i++)
            parents[up][i] = parents[up - 1][parents[up - 1][i]];
}

int LCA(int u,int v)
{
	if(depth[u] < depth[v]) // 使满足u深度更大, 便于后面操作
        swap(u, v);

    // i求的是最多能向上跳2的几次幂步 
    int i = -1;
    while((1<<(i+1)) <= depth[u])
        ++i;

    // 平衡深度
    for (int j = i; j >= 0;j--)
        if(depth[u]-(1<<j)>=depth[v])
            u = parents[j][u];

    //特判刚好跳到一起（u，v有直接的祖宗关系）
    if(u==v)
        return u;

    // u和v一起向上跳
    for (int j = i; j >= 0;j--)
        if(parents[j][u]!=parents[j][v]){
            u = parents[j][u];
            v = parents[j][v];
        }

    //此时u已经位于LCA的子结点
    return parents[0][u];
}

void query(){
    while(m--){
        int u, v, ans;
        u = read(), v = read();
        ans = LCA(u, v);
        printf("%d\n", ans);
    }
}

int main()
{

    init();
    getDepth_dfs(root);
    getParents();
    query();

    return 0;
}