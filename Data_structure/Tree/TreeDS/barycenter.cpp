//*树的重心
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 5e4 + 5;

vector<int> e[maxn];
queue<int> q;

//*btr为重心，dis为所有点到重心的距离和
//*si为删除重心后最大连通块的结点数
int n, si = maxn, btr, d[maxn], dis;
int size[maxn], sum[maxn];
bool vis[maxn];

int dfs(int u){
    vis[u] = true;
    int size = 0, sum = 1;
    //size为u的最大子树的节点数
    //sum为以u为根的树的节点数
    for (int i = 0; i < e[u].size();i++){
        int v = e[u][i];
        if(vis[v])
            continue;
        int s = dfs(v);
        //s为以v为根的树的节点数
        size = max(size, s);
        sum += s;
        
    }
    int mx = max(size, n - sum);
    if(si>mx||(si==mx)&&(btr>u))
        btr = u, si = mx;
    //si = min(si, max(size, n - sum));
    return sum;
}

void bfs(){
    q.push(btr);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size();i++){
            int v = e[u][i];
            if(d[v]||v==btr)  //防止重复遍历
                continue;
            d[v] = d[u] + 1;
            dis += d[v];
            q.push(v);
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    //for (int i = 1; i <= n;i++)
    //    sum[i] = dfs(i);
    memset(vis, false, sizeof(vis));
    bfs();
    printf("%d %d", btr, dis);
    return 0;
}