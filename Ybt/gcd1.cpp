#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, gcd;
	cin >> m >> n;
	gcd = m < n ? m : n;
	int t = (m % gcd == 0) + (n % gcd == 0);
	while (t != 2)
	{
		gcd--;
		t = (m % gcd == 0) + (n % gcd == 0);
	}
	cout << gcd << endl;
	system("pause");
	return 0;
}
