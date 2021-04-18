#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10;

int n,ans;
int a[maxn][maxn],f[maxn][maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            scanf("%d", &a[i][j]);
    for (int i = n; i >= 1;i--)
        for (int j = 1; j <= i;j++)
            f[i][j] = max(f[i + 1][j + 1], f[i + 1][j]) + a[i][j];
    printf("%d", f[1][1]);
    return 0;
}