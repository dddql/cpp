#include <iostream>
#include <cmath>

using namespace std;

int n, m;

int main()
{
    cin>>n>>m;

    if (n>m)
        cout<<pow(n%m, 2);
    else if (n==m)
        cout<<0;
    else
        cout<<n*n;
    return 0;
}