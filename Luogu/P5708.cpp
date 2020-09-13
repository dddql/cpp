#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, p;
    double s;
    cin >> a >> b >> c;
    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(1) << s;
    return 0;
}