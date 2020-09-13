#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i, sum1 = 0, sum2 = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum2 += i;
		else
			sum1 += i;
	}
	cout << sum1 << endl;
	cout << sum2 << endl;
	system("pause");
	return 0;
}
