#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 5;

int n;
int a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            scanf("%d", &a[i][j]);
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n;i++)
        for (int j = 1; j <= i;j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
    int ans = 0;
    for (int i = 1; i <= n;i++)
        ans = max(ans, dp[n][i]);
    printf("%d", ans);
    return 0;
}