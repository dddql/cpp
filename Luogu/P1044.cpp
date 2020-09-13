#include <cstdio>
int n;
long long h[20] = {1, 1};
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n;i++)
        for (int j = 0; j < i;j++)
            h[i] += h[j] * h[i - j - 1];
    printf("%d", h[n]);
    return 0;
}