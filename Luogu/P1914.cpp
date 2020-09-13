#include <bits/stdc++.h>
using namespace std;
char pre[50];
int main()
{
    int n;
    cin >> n >> endl;
    gets(pre);
    for (int i = 0; i < 50; i++)
    {
        if (pre[i] == 'z')
            pre[i] = 'a';
        pre[i] += n;
    }
    puts(pre);
    return 0;
}