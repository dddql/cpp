//*复杂度O(KE)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5+10;

struct edge{
    int next;
    int len;
};

struct queue{
    int head = 1, tail = 0;
    int a[maxn];

    void push(int x){
        a[++tail] = x;
    }
    void pop(){
        head++;
    }
    int front(){
        return a[head];
    }
    bool empty(){
        return head > tail;
    }
    int size(){
        return tail - head + 1;
    }
} q;

vector <edge> e[maxn];

int n, m, s;
int dis[maxn], exi[maxn][maxn];
bool vis[maxn];

void add_edge(int u,int v,int l){
    e[u].push_back((edge){v, l});
    e[v].push_back((edge){u, l});
}

void SPFA(int start){
    q.push(start), vis[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop(), vis[x] = false;
        for (int i = 0; i < e[x].size();i++){
            int t = e[x][i].next;
            if(dis[t]>dis[x]+e[x][i].len){
                dis[t] = dis[x] + e[x][i].len;
                if(!vis[t])
                    q.push(t), vis[t] = true;
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m;i++){
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        add_edge(u, v, l);
    }

    memset(dis, 0x3f, sizeof(dis)), dis[s] = 0;

    SPFA(s);

    for (int i = 1; i <= n;i++)
        printf("%d ", dis[i]);
    return 0;
}