#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, s;
int dis[maxn];
bool vis[maxn];

struct edge{
    int next;
    int len;
};

struct heap{
    int heap_size = 0;
    int heap[maxn], fheap[maxn];

    int top(){
        return heap[1];
    }

    void push(int x){
        heap[++heap_size] = x;
        fheap[x] = heap_size;
        int now = heap_size;
        while(now>1){
            int fa = now >> 1;
            if(dis[heap[now]]<dis[heap[fa]]){
                swap(heap[now], heap[fa]);
                now = fa;
            }
            else
                break;
        }
    }

    int get(){
        int tmp = heap[1], now = 1;
        heap[1] = heap[heap_size--];
        while(now<=(heap_size>>1)){
            int ls = now << 1, rs = now << 1 | 1;
            int min_son = rs > heap_size ? ls : (dis[heap[ls]] > dis[heap[rs]] ? rs : ls);
            if(dis[heap[now]]>dis[heap[min_son]]){
                swap(heap[now], heap[min_son]);
                now = min_son;
                continue;
            }
            else
                break;
        }
        return tmp;
    }

    void adjust(int x){
        int now = fheap[x];
        while(now>1){
            int fa = now >> 1;
            if(dis[heap[now]]<dis[heap[fa]]){
                swap(heap[now], heap[fa]);
                now = fa;
            }
            else
                break;
        }
    }

    int size(){
        return heap_size;
    }

    bool empty(){
        return heap_size == 0;
    }
} h;

vector <edge> e[maxn];

void add_edge(int u,int v,int w){
    e[u].push_back((edge){v, w});
}

void dijkstra(int start){
    dis[start] = 0, h.push(start);
    while(!h.empty()){
        int x = h.get();
        if(vis[x])
            continue;
        vis[x] = true;
        for (int k = 0; k < e[x].size();k++){
            edge t = e[x][k];
            if(dis[t.next]>dis[x]+t.len&&!vis[t.next]){
                dis[t.next] = dis[x] + t.len;
                h.adjust(t.next);
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m;i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }

    for (int i = 1; i <= n;i++)
        h.push(i);

    dijkstra(s);

    for (int i = 1; i <= n;i++)
        printf("%d ", dis[i]);

    return 0;
}