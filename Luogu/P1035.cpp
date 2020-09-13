#include <cstdio>

int main()
{
    int n = 1, k;
    double Sn = 0;
    cin >> k;
    while (Sn <= k)
    {
        Sn += (1.0 / n);
        n++;
    }
    n--;
    cout << n << endl;
    return 0;
}