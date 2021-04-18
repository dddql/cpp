#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 16;

struct edge{
    int to;
    int w;
};

vector<edge> e[maxn];
queue<int> q;
int a[maxn][maxn];
int in[maxn], pre[maxn], ans[maxn];
int f[maxn];
int n, m, tot;

void input(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            if(a[i][j]){
                e[i].push_back((edge){j, a[i][j]});
                in[j]++;
            }
}

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size();i++){
            int next = e[x][i].to;
            in[next]--;
            if(f[x] + e[x][i].w<f[next]){
                f[next] = f[x] + e[x][i].w;
                pre[next] = x;
            }
            //f[next] = min(f[x] + e[x][i].w, f[next]);
            if(!in[next])
                q.push(next);
        }
    }
}

int main()
{
    memset(f, 127, sizeof(f)), f[1] = 0;
    input();

    q.push(1);
    bfs();

    printf("%d\n", f[n]);
    for (int i = n;i;i = pre[i])
        ans[++tot] = i;
    for (int i = tot; i >= 1;i--)
        printf("%d ", ans[i]);
    return 0;
}