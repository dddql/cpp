#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;

vector<int> e[maxn];

struct stack{
    int a[maxn], tot = 0;
    void push(int x){
        a[++tot] = x;
    }
    void push(){
        tot--;
    }
    void pop(){
        tot--;
    }
    int top(){
        return a[tot];
    }
    bool empty(){
        return tot == 0;
    }
    int size(){
        return tot;
    }
} s;

int n, m;
int num, t, ans;

int dfn[maxn], low[maxn];
bool out[maxn], ext[maxn][maxn];
int cnt[maxn], co[maxn];

void add_edge(int u,int v){
    e[u].push_back(v);
    ext[u][v] = true;
}

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    s.push(u);
    for (int i = 0; i < e[u].size();i++){
        int v = e[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!out[v])
            low[u] = min(low[u], low[v]);
    }
    if(dfn[u]==low[u]){
        t++;
        while(s.top()!=u){
            out[s.top()] = true, co[s.top()] = t, cnt[co[s.top()]]++;
            s.pop();
        }
        out[s.top()] = true, co[s.top()] = t, cnt[co[s.top()]]++;
        s.pop();
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(!ext[u][v])
            add_edge(u, v);
    }
    for (int i = 1; i <= n;i++)
        if(!dfn[i])
            tarjan(i);
    for (int i = 1; i <= t;i++)
        if(cnt[i]>1)
            ans++;
    printf("%d", ans);
    return 0;
}