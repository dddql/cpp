#include <iostream>
#include <algorithm>
#include <string>       //*字符串操作需包含
using namespace std;

int n;
string a[21];

bool cmp(string a,string b){
    return a + b > b + a;       //*假如a=32,b=321,确保32321在32132前
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin>>a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n;i++)
        cout<<a[i];
    return 0;
}