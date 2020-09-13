#include <cstdio>

int n;
int a[100001], b[100001], g[100001], k[100001];
int x, y;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
    scanf("%d%d", &x, &y);
    for (int i = n; i >= 1; i--)
    {
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}