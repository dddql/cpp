#include <bits/stdc++.h>
using namespace std;
float f(float x, int n)
{
    if (n == 1)
        return sqrt(x + 1);
    else
        return sqrt(n + f(x, (n - 1)));
}
int main()
{
    float x;
    int n;
    cin >> x >> n;
    printf("%.3f", f(x, n));
    return 0;
}