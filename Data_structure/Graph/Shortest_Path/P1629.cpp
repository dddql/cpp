#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e3+5;
const int INF = 0x3f3f3f3f;

struct edge{
    int to;
    int length;
};

struct node{
    int dis;
    int pos;
    bool operator<(const node &x)const{
        return x.dis < dis;
    }
};

vector<edge> e[maxn * 2];
priority_queue<node> q;

int n, m;
int dis[maxn * 2];
bool vis[maxn * 2];

void Dijkstra(int at){
    dis[at] = 0;
    q.push((node){dis[at], at});

    while(!q.empty()){
        node tmp = q.top();
        int x = tmp.pos, d = tmp.dis;
        q.pop();
        if(vis[x])
            continue;
        vis[x] = true;
        for (register int i = 0; i < e[x].size();i++){
            int t = e[x][i].to;
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
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));

    for (register int i = 1; i <= m;i++){
        register int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back((edge){v, w});
        e[v + n].push_back((edge){u + n, w});
    }

    int total_time = 0;

    Dijkstra(1);
    for (register int i = 2; i <= n;i++)
        total_time += dis[i];

    memset(vis, 0, sizeof(vis));

    Dijkstra(1 + n);
    for (register int i = 2; i <= n;i++)
        total_time += dis[i + n];

    printf("%d", total_time);
    return 0;
}