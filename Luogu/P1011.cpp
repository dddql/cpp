#include <cstdio>

int a, n, m, x, y;
int p[21];
int fib[21],sum[21];

void init_fib() {
    fib[0] = 0, fib[1] = 1;
    sum[0] = 0, sum[1] = 1;
    for (int i = 2; i <= n;i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        sum[i] = sum[i-1] + fib[i];
    }
}

long long cal(int x) {
    p[1] = p[2] = a;
    p[3] = 2 * a;
    if(x<=3)
        return p[x];

    y = (m - (sum[n - 5]+2) * a) / sum[n - 4];

    p[x] = (sum[x - 4] +2)* a + sum[x - 3] * y;

    return p[x];
}
int main()
{
    scanf("%d%d%d%d", &a, &n, &m, &x);
    init_fib();
    printf("%lld", cal(x));
    return 0;
}