#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Local, Luogu;
    Local = 5 * n;
    Luogu = 3 * n + 11;
    if (Local < Luogu)
        cout << "Local";
    else
        cout << "Luogu";
    return 0;
}