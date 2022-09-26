#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1e4+5;

vector<int> e[maxn];
vector<int> E[maxn];

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
int num, t;
int flag, count;

//*dfn[]:结点u搜索次序的时间戳（固定）
//*low[]:结点u或u的子树能够到达的最早的*栈中*结点的dfn值（动态更新）
int dfn[maxn], low[maxn];

//*记录是否出栈
bool pop[maxn];

bool ext[maxn][maxn];

int co[maxn], cnt[maxn];

int out[maxn];

void add_edge(int u,int v){
    e[u].push_back(v);
    ext[u][v] = true;
}

void new_graph(){
    memset(ext, false, sizeof(ext));
    for (int i = 1; i <= n;i++)
        for (int j = 0; j < e[i].size();j++){
            int x = co[i], y = co[e[i][j]];
            if(x!=y&&!ext[x][y])
                E[x].push_back(y), ext[x][y] = true, out[x]++;
        }
}

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    s.push(u);

    //*遍历点u的邻接表
    for (int i = 0; i < e[u].size();i++){
        int v = e[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }

        //*防止使用已经出栈的点更新
        else if(!pop[v])
            low[u] = min(low[u], low[v]);
    }

    //*找到强连通分量的根即可输出
    if(dfn[u]==low[u]){
        t++;
        while(s.top()!=u){
            //printf("%d ", s.top());
            pop[s.top()] = true, co[s.top()] = t, cnt[t]++;
            s.pop();
        }
        //printf("%d", s.top());
        pop[s.top()] = true, co[s.top()] = t, cnt[t]++;
        s.pop();
        //printf("\n");
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
    new_graph();
    for (int i = 1; i <= t;i++){
        if(out[i]==0){
            count++;
            flag = i;
        }
        if(count==2){
            printf("0");
            return 0;
        }
    }
    printf("%d", cnt[flag]);
    return 0;
}