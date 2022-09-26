#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define gc getchar()

inline ull rd()
{
    ull x = 0;
    char s = gc;
    while (!isdigit(s))
        s = gc;
    while (isdigit(s))
        x = (x << 1) + (x << 3) + s - '0', s = gc;
    return x;
}
ull n, m, c, k, ans, lim, hv;

int main()
{
    n = rd(), m = rd(), c = rd(), k = rd();
    for (int i = 1; i <= n; i++)
        hv |= rd(); // 统计每个位是否有 1
    for (int i = 1; i <= m; i++)
        lim |= 1ull << rd(), rd(); // 统计有限制的位
    for (int i = 0; i < k; i++)
        ans += !((lim >> i) & 1) || ((hv >> i) & 1); // 如果当前位有 1, 或者没有限制，那么都可以选
    if (ans == 64 && !n)
        puts("18446744073709551616");
    else
        cout << (ans == 64 ? -n : (1ull << ans) - n) << endl;
    return 0;
}