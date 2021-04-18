//*输入每条边，邻接矩阵储存
#include <cstdio>

const int maxn = 1005;

int n, e;    //*点数n,边数e
int v[maxn][maxn];

int main()
{
    scanf("%d%d", &n, &e);

    for (int i = 1; i <= e;i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        v[a][b] = v[b][a] = w;
    }

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n; j++)
            if (v[i][j])
                    printf("edge from point %d to %d with length %d\n", i, j, v[i][j]);
    return 0;
}