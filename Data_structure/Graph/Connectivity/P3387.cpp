#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

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
struct queue{
    int a[maxn];
    int head = 1, tail = 0;

    void push(int x){
        a[++tail] = x;
    }

    void pop(){
        head++;
    }

    int front(){
        return a[head];
    }

    int size(){
        return tail - head + 1;
    }

    bool empty(){
        return head>tail;
    }
} q;

int n, m;
int num, t, ans;

//*点权
int a[maxn];
int A[maxn];

int dp[maxn];

//*dfn[]:结点u搜索次序的时间戳（固定）
//*low[]:结点u或u的子树能够到达的最早的*栈中*结点的dfn值（动态更新）
int dfn[maxn], low[maxn];

//*记录是否出栈
bool out[maxn];

//*防止读入重边
bool ext[maxn][maxn];

//*记录点u所属的强连通分量的编号
int co[maxn];

int in[maxn];

void add_edge(int u,int v){
    e[u].push_back(v);
    ext[u][v] = true;
}

void new_graph(){
    for (int i = 1; i <= n;i++)
        A[co[i]] += a[i];

    memset(ext, false, sizeof(ext));
    for (int i = 1; i <= n;i++)
        for (int j = 0; j < e[i].size();j++){
            int x = co[i], y = co[e[i][j]];
            if(x!=y&&!ext[x][y])
                E[x].push_back(y), ext[x][y] = true, in[y]++;
        }

    for (int i = 1; i <= t;i++)
        if(!in[i]){
            q.push(i);
            dp[i] = A[i];
        }
}

void bfs(){
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < E[u].size();i++){
            int v = E[u][i];
            in[v]--;
            if(!in[v])
                q.push(v);
            dp[v] = max(dp[v], dp[u] + A[v]);
        }
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
        else if(!out[v])
            low[u] = min(low[u],low[v]);
    }

    //*找到强连通分量的根即可输出
    if(dfn[u]==low[u]){
        t++;
        while(s.top()!=u){
            //printf("%d ", s.top());
            out[s.top()] = true, co[s.top()] = t;
            s.pop();
        }
        //printf("%d", s.top());
        out[s.top()] = true, co[s.top()] = t;
        s.pop();
        //printf("\n");
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if (!ext[u][v])
            add_edge(u, v);
    }

    printf("\n");

    for (int i = 1; i <= n;i++)
        if(!dfn[i])
            tarjan(i);

    new_graph();

    bfs();

    for (int i = 1; i <= t;i++)
        ans = max(ans, dp[i]);
    printf("%d", ans);

    return 0;
}

