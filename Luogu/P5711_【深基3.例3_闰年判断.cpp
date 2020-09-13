#include <bits/stdc++.h>
using namespace std;
bool leap(int n)
{
    if (n % 4 == 0 && n % 100 != 0)
        return true;
    if (n % 100 == 0 && n % 400 == 0)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (leap(n))
        cout << 1;
    else
        cout << 0;
    return 0;
}