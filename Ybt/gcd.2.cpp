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

while(1)
{
	c = a % b;
	if (c != 0)
	{
		a = b;
		b = c;
	}
	else
	{
		break;
	}
}
printf("%d", b);
