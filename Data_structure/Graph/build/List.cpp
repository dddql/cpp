#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1005;

struct edge{
    int next;
    int length;
};

vector<edge> e[maxn];

int n, m;
int v[maxn][maxn];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m;i++){
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        e[u].push_back((edge){v, l});
        //e[v].push_back((edge){u, l});
    }

    for (int i = 1; i <= n;i++)
        for (int j = 0; j < e[i].size();j++)
            v[i][e[i][j].next] = e[i][j].length;

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    return 0;
}