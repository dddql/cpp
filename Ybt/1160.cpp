#include <bits/stdc++.h>
using namespace std;
bool first = true;
int invert(int n)
{
    int d = n % 10;
    if (first)
    {
        if (d != 0)
            cout << d;
        first = false;
    }
    else
        cout << d;
    n /= 10;
    if (n <= 10)
        return n;
    else
        return invert(n);
}
int main()
{
    int n;
    cin >> n;
    cout << invert(n);
    return 0;
}