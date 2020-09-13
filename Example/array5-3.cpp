#include <iostream>
#include <cstdio>
#include <cstring>
#define MANX 100000
using namespace std;
int a[MANX];
int main()
{
	int m, n, first = 1;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			if (j % i == 0)
				a[j] = !a[j];
	}
	for (int i = 1; i <= m; i++)
		if (a[i])
		{
			if (first)
				first = 0;
			else
				cout << " ";
			cout << i;
		}
	cout << "\n";
	return 0;
}
