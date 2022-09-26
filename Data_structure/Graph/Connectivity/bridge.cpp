#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 2e4+5;

struct edge{
    int to;
    bool cut;
};
vector<edge> e[maxn];

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

struct set{
    int fa[maxn], size[maxn];

    void build(int n){
        for (int i = 1; i <= n;i++)
            fa[i] = i, size[i] = 1;
    }

    int find(int x){
        if(x == fa[x])
            return x;
        return fa[x] = find(fa[x]);     //*路径压缩
    }

    void join(int a,int b){
        int f1 = find(a);
        int f2 = find(b);
        if(size[f1]<size[f2]){          //*按秩合并
            fa[f1] = f2;
            size[f2] += size[f1];
        }
        else{
            fa[f2] = f1;
            size[f1] += size[f2];
        }
    }
} st;

int n, m;
int num ,root = 1, ans, t;

//low[]的含义在无向图中发生了变化
int dfn[maxn], low[maxn], co[maxn][maxn];

bool cut[maxn];

void add_edge(int u,int v){
    e[u].push_back((edge){v,false});
    e[v].push_back((edge){u,false});
}

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    s.push(u);

    int cnt = 0;        //*使用局部变量，计数以u为根的子树个数
    for (int i = 0; i < e[u].size();i++){
        edge v = e[u][i];
        if(!dfn[v]){
            cnt++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(dfn[u]<low[v])
                v.cut = true;
            //*此时已经处理完v，回溯到u
        }
        else                    //*此时v已在u前被访问过
            low[u] = min(low[u], dfn[v]);//*需防止v回到u
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
    
    return 0;
}