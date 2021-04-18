#include <cstdio>

const int maxn = 1e3 + 5;

int head[maxn], nxt[maxn], to[maxn];
bool visit[maxn];
int cnt, n, m;

void add(int u,int v){
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void build(){
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
}

void dfs(int x){
    if(visit[x])
        return;
    visit[x] = true;
    for (int i = head[x];i;i = nxt[x])
        dfs(to[i]);
    printf("%d ", x);
}

int main()
{
    scanf("%d%d", &n, &m);
    build();
    dfs(1);
    return 0;
}