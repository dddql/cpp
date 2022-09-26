#include <cstdio>

typedef unsigned long long ull;

const int maxn = 1e6 + 10;

ull n, m, c, k;
ull _lim, ani, tmp;
ull ans;
bool flag[maxn];

inline ull read()
{
    ull x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

int main()
{
    //freopen("zoo3.in", "r", stdin);
    n = read(), m = read(), c = read(), k = read();
    for (int i = 1; i <= n; i++)
        ani |= read();
    for (int i = 1; i <= m; i++)
        _lim |= (1ull << read()), tmp = read();

    for (int i = 0; i < k; i++)
        ans += !((_lim >> i) & 1) || ((ani >> i) & 1);

    if (ans == 64)
        if (n)
            printf("%llu", -n);
        else
            printf("18446744073709551616");
    else
        printf("%llu", (1ull << ans) - n);
    //freopen("3.out", "w", stdout);

    return 0;
}
/*
000 001 010 011
100 101 110 111
*/