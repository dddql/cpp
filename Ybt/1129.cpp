#include <bits/stdc++.h>
using namespace std;
int main()
{
    char st[255];
    gets(st);
    int n;
    for (int i = 0; i <= 254; i++)
    {
        if (st[i] <= 57 && st[i] >= 49)
            n++;
    }
    cout << n;
    return 0;
}