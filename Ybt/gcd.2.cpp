#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, r;
	cin >> m >> n;
	r = m % n;
	while (r)
	{
		m = n;
		n = r;
		r = m % n;
	}
	cout << n << endl;
	system("pause");
	return 0;
}
