#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    float t, s;
    cin >> m >> t >> s;
    if (t == 0)
        cout << m;
    if ((m * t) < s)
        cout << 0;
    else
        cout << (m - ceil(s / t));
    return 0;
}