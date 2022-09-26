#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 82;

struct Bigint
{
    int a[maxn];
    int len;

    Bigint()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }

    /*
    Bigint(const int);
    Bigint(const char *);*/

    int &operator[](int i)
    {
        return a[i];
    }

    //*字符串赋值
    Bigint operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            a[i] = num[len - i - 1] - '0';
        return *this;
    }

    //*整数赋值
    Bigint operator=(const int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    Bigint(const int num) { *this = num; }
    Bigint(const char *num) { *this = num; }

    bool operator<(const Bigint &x) const
    {
        if (len != x.len)
            return len < x.len;
        for (int i = len - 1; i >= 0; i--)
            if (a[i] != x.a[i])
                return a[i] < x.a[i];
        return false;
    }

    bool operator>(const Bigint &x) const { return x < *this; }
    bool operator<=(const Bigint &x) const { return !(x < *this); }
    bool operator>=(const Bigint &x) const { return !(*this < x); }
    bool operator==(const Bigint &x) const { return !(x < *this || *this < x); }
    bool operator!=(const Bigint &x) const { return x < *this || *this < x; }

    /*
    Bigint operator+=(const Bigint &a)
    {
        *this = *this + a;
        return *this;
    }

    Bigint operator*=(const Bigint &a)
    {
        *this = *this * a;
        return *this;
    }
    */

    void flatten()
    {
        while (!a[len - 1])
            --len;
    }

    void print()
    {
        for (int i = max(len, 1); i >= 1; i--)
            printf("%d", a[i]);
        printf("\n");
    }
};

ostream &operator<<(ostream &out, const Bigint &x)
{
    for (int i = x.len - 1; i >= 0; i--)
        cout << x.a[i];
    return out;
}

istream &operator>>(istream &in, Bigint &x)
{
    char num[maxn];
    in >> num;
    x = num;
    return in;
}

Bigint operator+(Bigint a, Bigint b)
{
    Bigint c;
    c.len = max(a.len, b.len) + 1;
    for (int i = 0, x = 0; i < c.len; i++)
    {
        c[i] += a[i] + b[i] + x;
        x = c[i] / 10;
        c[i] %= 10;
    }
    c.flatten();
    return c;
}

Bigint operator+=(Bigint a, Bigint b)
{
    Bigint c;
    c = a + b;
    return c;
}

Bigint operator-(Bigint a, Bigint b)
{
    Bigint c;
    c.len = max(a.len, b.len) + 1;
    for (int i = 0; i < c.len; i++)
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            c[i + 1]--;
            c[i] += 10;
        }
    }
    c.flatten();
    return c;
}

Bigint operator*(Bigint a, int b)
{
    Bigint c;
    c.len = a.len + 11;
    for (int i = 0, x = 0; i < c.len; i++)
    {
        c[i] = a[i] * b + x;
        x = c[i] / 10;
        c[i] %= 10;
    }
    c.flatten();
    return c;
}

Bigint operator*(Bigint a, Bigint b)
{
    Bigint c;
    c.len = a.len + b.len;
    for (int i = 0; i < a.len; i++)
        for (int j = 0; j < b.len; j++)
        {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    c.flatten();
    return c;
}

int n, m;
int a[maxn][maxn];
Bigint dp[maxn][maxn][maxn];
Bigint ans;

Bigint dfs(int k, int i, int j)
{
    if (dp[k][i][j] != 0)
        return dp[k][i][j];
    else if (i == j)
        return a[k][i] * (1 << (m - 1));
    else
        return dp[k][i][j] = max(dfs(k, i + 1, j) + a[k][i] * (1 << (m - j + i)), dfs(k, i, j - 1) + a[k][j] * (1 << (m - j + i)));
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        ans += dfs(i, 1, m);

    cout << ans << endl;

    return 0;
}