#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 5e5 + 10;
const int maxm = 2e6 + 10;

vector<int> e[maxn];

int n, m, q;
int SUM;
int a[maxn], d[maxn];
bool vis[maxn];

inline int read()
{
    char c = getchar();
    int x = 0,s = 1;
    while(c < '0' || c > '9') {
        if(c == '-') s = -1;c = getchar();
    }//是符号
    while(c >= '0' && c <= '9') {
        x = x*10 + c -'0';c = getchar();
    }//是数字
    return x*s;
}

int dfs(int u,int v){
    int sum = 0;
    if(u==v){
        if(!vis[v]){
            sum += a[v];
            a[v] = 0;
            vis[v] = true;
        }
        return sum;
    }
    for (int i = 0; i < e[u] size();;i++){
        int t = e[u][i];
        vis[t] = true;
        sum += dfs(t,v);
    }
    return sum;
}

void tarjan(){

}

void LCA(int u,int v){

}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        a[i] = read();
    for (int i = 1; i <= m;i++){
        int u = read();
        int v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    q = read();
    for (int i = 1; i <= q;i++){
        int x = read();
        int y = read();
        SUM += dfs(x);
    }
    printf("%d", SUM);

    return 0;
}