#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100005;

vector<int> e[maxn];
int a[maxn];

int n, m;

void dfs(int x,int d){
    if(a[x])
        return;
    a[x] = d;
    for (int i = 0; i < e[x].size();i++)
        dfs(e[x][i], d);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        e[v].push_back(u);
    }

    for (int i = n; i >= 1;i--)
        dfs(i, i);

    for (int i = 1; i <= n;i++)
        printf("%d ", a[i]);

    return 0;
}