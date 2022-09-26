//*递归，DP，搜索
#include <cstdio>

const int maxn = 8;
const int maxk = 4;

int n,k;
int f[maxn][maxk];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
        f[i][1] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = 2; j <= k;j++)
            if(i>=j)
                f[i][j] = f[i - 1][j - 1] + f[i - j][j];
    printf("%d", f[n][k]);
    return 0;
}