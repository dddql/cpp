//*最长不下降子序列，及其最少个数

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5+1;

int n, ans_1, ans_2;
int a[maxn], f[maxn];

int main(){
    while(scanf("%d",&a[++n])!=EOF);n--;
    for(int i = 1;i<=n;i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1;i--){
        f[i] = 1;
        for (int j = i+1; j <= n;j++)
            if(a[j]<=a[i])
                f[i]=max(f[i],f[j]+1);
        ans_1 = max(ans_1, f[i]);
    }

    for (int i = 1; i <= n;i++){
        f[i] = 1;
        for (int j = 1; j < i;j++)
            if(a[j]<a[i])
                f[i] = max(f[i], f[j] + 1);
        ans_2 = max(ans_2, f[i]);
    }
    printf("%d\n%d", ans_1,ans_2);
    return 0;
}