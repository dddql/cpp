#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, ans = 1;
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
	{
		ans *= a;
		ans %= 1000;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
