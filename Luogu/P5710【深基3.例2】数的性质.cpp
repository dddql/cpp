#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int flag_1, flag_2;
    cin >> n;
    if (n % 2 == 0)
        flag_1 = 1;
    if (n >= 4 && n <= 12)
        flag_2 = 1;
    switch (flag_1 + flag_2)
    {
    case 2:
        cout << "1 1 0 0";
        break;
    case 1:
        cout << "0 1 1 0";
        break;
    case 0:
        cout << "0 0 0 1";
        break;
    default:
        break;
    }
    return 0;
}