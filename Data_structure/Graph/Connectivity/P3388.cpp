#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 2e4+5;

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
int num ,root = 1, ans, t;

//low[]的含义在无向图中发生了变化
int dfn[maxn], low[maxn], co[maxn][maxn];

bool cut[maxn];

void add_edge(int u,int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

void tarjan(int u){
    dfn[u] = low[u] = ++num;

    int cnt = 0;        //*使用局部变量，计数以u为根的子树个数
    for (int i = 0; i < e[u].size();i++){
        int v = e[u][i];
        if(!dfn[v]){
            cnt++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if((u==root&&cnt>1)||(u!=root&&dfn[u]<=low[v]))
                cut[u] = true, ans++;
            //*此时已经处理完v，回溯到u
        }
        else                    //*此时v已在u前被访问过
            low[u] = min(low[u], dfn[v]);
    }
}

int main(){
    //freopen("")
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    tarjan(1);
    printf("%d\n", ans);
    for (int i = 1; i <= n;i++)
        if(cut[i])
            printf("%d ", i);
    return 0;
}