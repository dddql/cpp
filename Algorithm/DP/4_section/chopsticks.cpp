/*
f[i][j]表示-前i根-筷子凑成j双筷子的长度最小差平方和
若不取用第i根筷子：
    f[i][j] = f[i-1][j];
若取用：
    f[i][j] = f[i-2][j-1] + (a[i-1]-a[i])^2;
注意根据题目实际意义确定循环范围：
    2<=i<=n, 1<=j<=i/2
!!本题属于区间DP的一种特例，(区间长度始终为2)
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e3;
const int INF = 0x3f3f3f3f;

int n,k;
int a[maxn], f[maxn][maxn];

int len(int a,int b){
    return pow(a - b, 2);
}

int main(){
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= n;i++)
        f[i][0] = 0;

    scanf("%d%d", &n, &k);

    if(n<(k+3)*2){
        printf("-1");
        return 0;
    }

    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    for (int i = 2; i <= n;i++)
        for (int j = 1; j <= i / 2;j++)
            f[i][j] = min(f[i - 1][j], f[i - 2][j - 1] + len(a[i - 1], a[i]));

    printf("%d", f[n][k + 3]);
    return 0;
}