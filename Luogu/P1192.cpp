#include <cstdio>

int n, k, sum[100001];

int main()
{
    scanf("%d%d", &n, &k);
    sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && j <= i; j++)
            sum[i] += sum[i - j] % 100003;
        sum[i] %= 100003;
    }
    printf("%d", sum[n] % 100003);
    return 0;
}