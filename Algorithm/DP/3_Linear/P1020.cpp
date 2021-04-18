//*最长不下降子序列，及其个数
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10;

int n;
int a[maxn], f[maxn], b[maxn];

int main(){
    while(cin>>a[++n]);n--;
    for (int i = 1; i <= n;i++){
        int maxt = 1;
        for (int j = 1; j <= i;j++)
            if(a[i]<=a[j])
                maxt = max(maxt, f[j] + 1);
        f[i] = maxt;
    }

    int t = 1;
    b[1] = a[1];
    for (int i = 2; i <= n;i++){
        int minn = 1e9, flag = 0;
        for (int j = 1; j < i;j++){
            if(minn>(b[j]-a[i])&&(b[j]>a[i])){
                minn = b[j]-a[i];
                flag = j;
            }
        }
        if(flag)
            b[flag] = a[i];
        else
            b[++t] = a[i];
    }
    printf("%d\n%d", f[n],t);
    return 0;
}