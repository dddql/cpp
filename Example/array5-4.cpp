#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, s, f, i;
	scanf("%d %d", &n, &m);
	int a[n];
	for (i = 1; i <= n; i++)
		a[i] = false;
	f = s = i = 0;
	do
	{
		i++;
		if (i == n + 1)
			i = 1;
		if (a[i] == false)
			s++;
		if (s == m)
		{
			s = 0;
			printf("%d ", i);
			a[i] = true;
			f++;
		}
	} while (f != n);
	return 0;
}
