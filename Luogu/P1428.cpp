#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sta[n], ans[n];
    for (int i = 0; i < n; i++)
        cin >> sta[i];
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < i; j++)
        {
            if (sta[j] < sta[i])
                t++;
        }
        ans[i] = t;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}