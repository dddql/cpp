#include <cstdio>
#include <iostream>
using namespace std;
template <class T>
inline void read(T &a)
{
    char c = getchar();
    int f = 1;
    a = 0;
    while (c > '9' || c < '0')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c <= '9' && c >= '0')
        a = (a << 1) + (a << 3) + c - 48, c = getchar();
    a *= f;
}
template <class T>
void write(T a)
{
    if (a < 0)
        putchar('-'), a = -a;
    if (a > 9)
        write(a / 10);
    putchar(a % 10 + 48);
}
const int o = 110, MOD = 998244353, N = 2e6 + 10;
#define int long long
int T, n, m, a[o], b[o], f[o][o], fac[N], inv[N];
int qp(int b, int f)
{
    if (!f)
        return 1;
    int rcd = qp(b, f >> 1);
    return (f & 1) ? rcd * rcd % MOD * b % MOD : rcd * rcd % MOD;
}
inline int Inv(int x) { return qp(x, MOD - 2); }
inline int C(int x, int y)
{
    if (x < y)
        return 0;
    return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
inline int det()
{
    int res = 1, r, d, cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        r = 0;
        for (int j = i; j <= m; ++j)
            if (f[j][i])
                r = j;
        if (!r)
            return 0;
        if (i ^ r)
        {
            ++cnt;
            for (int j = i; j <= m; ++j)
                f[i][j] ^= f[r][j] ^= f[i][j] ^= f[r][j];
        }
        for (int j = i + 1; j <= m; ++j)
        {
            d = f[j][i] * Inv(f[i][i]) % MOD;
            for (int k = i; k <= m; ++k)
                f[j][k] = (f[j][k] - f[i][k] * d % MOD + MOD) % MOD;
        }
        res = res * f[i][i] % MOD;
    }
    return (res * qp(-1, cnt) % MOD + MOD) % MOD;
}
signed main()
{
    read(T);
    for (int i = fac[0] = inv[0] = 1; i < N; ++i)
        inv[i] = Inv(fac[i] = fac[i - 1] * i % MOD);
    while (T--)
    {
        read(n);
        read(m);
        for (int i = 1; i <= m; ++i)
            read(a[i]), read(b[i]);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                f[i][j] = C(n - 1 + b[j] - a[i], n - 1);
        write(det());
        putchar('\n');
    }
    return 0;
}