#include <bits/stdc++.h>
using namespace std;

int factorial(int x)
{
    if (x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}