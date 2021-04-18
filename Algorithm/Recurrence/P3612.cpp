#include <iostream>
#include <cstring>
using namespace std;

string s;
long long n, num, i;

int main()
{
    cin >> s >> n;
    num = s.length();
    while(n>num){
        i = num;
        while(n>(i<<1))
            i <<= 1;
        n -= (i + 1);
        if(n==0)
            n = i;
    }
    cout<<s[n-1];
    return 0;
}