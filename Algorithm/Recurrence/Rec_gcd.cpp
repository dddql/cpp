#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n)
{
    return m % n == 0 ? n : gcd(n, m % n);
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n);
    return 0;
}