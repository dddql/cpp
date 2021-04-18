#include <bits/stdc++.h>
#define l(a) for(int i = 0; i < a;i++)
#define d(a) (a)>=0?(a):(-a)
using namespace std;

int n, sum = 0, prod = 1, minn = 0xffffff;

struct dish{
    int s,b;
}d[25];

void dfs(int x){
    if(x >= n)
        return;
    prod *= d[x].s;
    sum += d[x].b;
    minn = min(minn, d((sum - prod)));
    dfs(x + 1);
    prod /= d[x].s;
    sum -= d[x].b;
    dfs(x + 1);
}

int main(){
    cin >> n;
    l(n)
        cin >> d[i].s >> d[i].b;
    dfs(0);
    cout << minn << endl;   
    return 0;
}