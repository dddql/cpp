//*邻接矩阵存图
//*输入邻接矩阵，输出边

#include <cstdio>

const int maxn = 1005;

int n;
int v[maxn][maxn];

int main()
{
    //*输入规模
    scanf("%d", &n);

    //*主体部分
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &v[i][j]);

    //*输出矩阵
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n; j++)
            if (v[i][j])
                    printf("edge from point %d to %d with length %d\n", i, j, v[i][j]);
    
    return 0;
}