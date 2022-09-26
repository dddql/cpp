#include <iostream>
#include <cstdio>
using namespace std;
struct Bigint{
	int len, a[maxn];

	Bigint(int x = 0)
	{
		memset(a, 0, sizeof(a));
		for (len = 1; x; len++)
		{
			a[len] = x % 10;
			x /= 10;
		}
		len--;
	}

	int &operator[](int i)
	{
		return a[i];
	}

	void flatten(int L)
	{
		len = L;
		for (int i = 1; i <= len; i++)
		{
			if (a[i] >= 10)
			{
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
			}
		}
		for (; !a[len];)
			len--;
	}

	void print()
	{
		for (int i = max(len, 1); i >= 1; i--)
			printf("%d", a[i]);
	}

	bool operator<=(const Bigint &x) const { return !(x < *this); }
	bool operator<(const Bigint &x) const { return x > *this; }
};

Bigint operator+(Bigint a, Bigint b)
{
	Bigint c;
	int len = max(a.len, b.len);
	for (int i = 1; i <= len; i++)
		c[i] += a[i] + b[i];
	c.flatten(len + 1);
	return c;
}

Bigint operator*(Bigint a, int b)
{
	Bigint c;
	int len = a.len;
	for (int i = 1; i <= len; i++)
		c[i] = a[i] * b;
	c.flatten(len + 11);
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

int main()
{
	Bigint S(0), i(1), m(1), p(0), q(1);
	int n;
	scanf("%d", &n);
	p = n;
	while (q <= n)
	{
		m = 1;
		i = q;
		while (i < n)
		{
			m = m * p;
			i = i + 1;
			p = p - 1;
		}
		S = S + m;
		p = n - q;
		q = q + 1;
	}
	S.print();
	return 0;
}
