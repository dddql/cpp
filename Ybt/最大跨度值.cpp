#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, score, maxs = -1, mins = 151;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score;
		maxs = maxs < score ? score : maxs;
		mins = mins > score ? score : mins;
	}
	int a = maxs - mins;
	cout << a << endl;
	system("pause");
	return 0;
}
