//!若题目数据非单调不减，需要进行排序
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e4 + 5;
const int INF = 0x7f7f7f7f;

struct edge{
    int next;
    int length;
};

struct node{
    int dis;
    int pos;
    bool operator<(const node &x)const{
        return x.dis < dis;
    }
};

vector<edge> e[maxn];
priority_queue<node> q;

int n, m, s;
int dis[maxn];
bool vis[maxn];

void add_edge(int u,int v,int w){
    e[u].push_back((edge){v, w});
}

void Dijkstra(int start){
    dis[start] = 0;
    q.push((node){0, start});
    while(!q.empty()){
        node tmp = q.top();
        int x = tmp.pos, d = tmp.dis;
        q.pop();
        if(vis[x])
            continue;
        vis[x] = true;
        for (int i = 0; i < e[x].size();i++){
            int t = e[x][i].next;
            if(dis[t]>dis[x]+e[x][i].length){
                dis[t] = dis[x] + e[x][i].length;
                if(!vis[t])
                    q.push((node){dis[t], t});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    memset(dis, 0x3f, sizeof(dis));
    for (register int i = 1; i <= m; i++){
        register int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    Dijkstra(s);
    for (int i = 1; i <= n;i++)
        printf("%d ", dis[i]);
    return 0;
}