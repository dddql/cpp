#include <cstdio>

const int N = 1001;

long long f[N], g[N];

int main()
{
    int n;
    scanf("%d", &n);
    f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = 1 + g[i / 2];
        g[i] = g[i - 1] + f[i];
    }
    printf("%lld", f[n]);
    return 0;
}