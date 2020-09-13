#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.141593;
int main()
{
    int T;
    cin >> T;
    if (T == 1)
    {
        cout << "I love Luogu!";
    }
    else if (T == 2)
    {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }
    else if (T == 3)
    {
        cout << floor(14 * 1.0 / 4) << endl;
        cout << 14 - (14 % 4) << endl;
        cout << 14 % 4;
    }
    else if (T == 4)
    {
        cout << fixed << setprecision(3) << 500.0 / 3;
    }
    else if (T == 5)
    {
        cout << (260 + 220) / (12 + 20);
    }
    else if (T == 6)
    {
        cout << sqrt(6 * 6 + 9 * 9);
    }
    else if (T == 7)
    {
        cout << 100 + 10 << endl;
        cout << 100 + 10 - 20 << endl;
        cout << 0 << endl;
    }
    else if (T == 8)
    {
        cout << 31.41593 << endl;
        cout << 78.539825 << endl;
        cout << 523.59883333333333333333333333333 << endl;
    }
    else if (T == 9)
    {
        int n = 1;
        for (int i = 2; i >= 0; i--)
            n = 2 * (n + 1);
        cout << n;
    }
    else if (T == 10)
    {
        float x, y;
        int ans;
        y = (30 * 8 - 6 * 10) * 1.0 / 24;
        x = 6 * 10 - 6 * y;
        ans = (x + 10 * y) / 10;
        cout << ans;
    }
    else if (T == 11)
    {
        cout << 100 * 1.0 / 3;
    }
    else if (T == 12)
    {
        cout << 'M' - 'A' + 1 << endl;
        cout << char('A' + 17);
    }
    else if (T == 13)
    {
        cout << 16;
    }
    else if (T == 14)
    {
        cout << 50 << endl;
    }
    return 0;
}