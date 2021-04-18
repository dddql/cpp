#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read()
{
	T f = 0, x = 0;
	char c = getchar();
	while (!isdigit(c))
		f = c == '-', c = getchar();
	while (isdigit(c))
		x = x * 10 + c - 48, c = getchar();
	return f ? -x : x;
}
namespace run
{
	const int N = 5009, mod = 998244353;
	inline int add(int x, int y) { return x + y >= mod ? x - mod + y : x + y; }
	inline int sub(int x, int y) { return x >= y ? x - y : x + mod - y; }
	inline int qpow(int x, int y)
	{
		int ret = 1;
		while (y)
		{
			if (y & 1)
				ret = 1LL * x * ret % mod;
			x = 1LL * x * x % mod, y >>= 1;
		}
		return ret;
	}
	int fac[N], ifac[N];
	inline int C(int n, int m)
	{
		if (n < 0 || m < 0 || n < m)
			return 0;
		return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
	}
	inline int calc(int n, int d, int m) { return sub(C(n, n - d - m), C(n, n - d - m + 1)); }

	int f[N][N], n, k, inv;
	int main()
	{
		n = read<int>(), k = read<int>(), inv = qpow(n, mod - 2);
		fac[0] = ifac[0] = ifac[1] = 1;
		for (int i = 1; i <= n; i++)
			fac[i] = 1LL * fac[i - 1] * i % mod;
		ifac[n] = qpow(fac[n], mod - 2);
		for (int i = n - 1; i >= 1; i--)
			ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod;
		assert(1LL * fac[n - 1] * ifac[n - 1] % mod == 1);

		f[0][0] = 1;
		for (int i = 1; i <= k; i++)
		{
			int sum = f[i - 1][n];
			for (int j = min(n, i); j; j--)
			{
				sum = (1LL * sum * j % mod * inv + f[i - 1][j - 1]) % mod;
				f[i][j] = 1LL * inv * (n - j + 1) % mod * sum % mod;
			}
		}
		int chk = 0;
		for (int i = 0; i <= n; i++)
			chk = add(chk, f[k][i]);
		assert(chk == 1);

		for (int i = 1; i <= n; i++)
			f[k][i] = 1LL * f[k][i] * qpow(C(n, i), mod - 2) % mod;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 2; j <= n && min(i, n - i) >= j / 2; j += 2)
				ans = (1LL * f[k][i] * calc(n, i, (j - 2 * i) / 2) % mod * j + ans) % mod;
		printf("%d\n", ans);
		return 0;
	}
} // namespace run
int main()
{
#ifdef my
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
	return run::main();
}
