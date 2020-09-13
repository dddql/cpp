#include <bits/stdc++.h>
using namespace std;
string cname[10];
int main()
{
    for (int i = 0; i != 10; i++)
        getline(cin, cname[i]);
    sort(cname, cname + 10);
    for (int i = 0; i != 10; i++)
        cout << cname[i] << endl;
    return 0;
}