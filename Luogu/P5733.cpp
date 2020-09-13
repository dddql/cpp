#include <bits/stdc++.h>
using namespace std;
char st[100];
int main()
{
    gets(st);
    for (int i = 0; i <= 99; i++)
        if (st[i] >= 97 && st[i] <= 122)
            st[i] -= 32;
    for (int i = 0; i <= 99; i++)
        cout << st[i];
    return 0;
}