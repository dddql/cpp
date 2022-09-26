#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e3;

vector<int> e[maxn];

int t;
int n, m;
int dfn[maxn], low[maxn];
bool cut[maxn];

void add_edge(int u,int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

void tarjan(int u){
    dfn[u] = low[u] = ++num;

    int cnt = 0;
    for (int i = 0; i < e[u].size();i++){
        int v = e[u][i];
        if(!dfn[v]){
            cnt++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if((u==root&&cnt>1)||(u!=root&&dfn[u]<=low[v]))
                cut[u] = true;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}

void input(){
    scanf("%d", &t);
    int v = 0;
    while(t!=0){
        int u;
        scanf("%d", &u), getchar();
        while(u!=0){
            char c;
            c = getchar();
            while(c!='\n'){
                if(c!=' ')
                    v = v * 10 + (c - '0');
                else
                    add_edge(u, v);
                c = getchar();
            }
            add_edge(u, v), v = 0;
            scanf("%d", &u), getchar();
        }
        scanf("%d", &t);
    }
}
int main(){
    input();
    /*
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    tarjan(1);
    for (int i = 1; i <= n;i++)
        if(cut[i])
            printf("%d ", i);*/
    return 0;
}