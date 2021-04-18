#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 5;

int n, x;
int lose[maxn], win[maxn], use[maxn];
int f[maxn];

int main(){
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n;i++)
        scanf("%d%d%d", &lose[i], &win[i], &use[i]);
    for (int i = 1; i <= n;i++)
        for (int j = x; j >= 0;j--){
            if(j>=use[i])
                f[j] = max(f[j] + lose[i], f[j - use[i]] + win[i]);
            else
                f[j] = f[j] + lose[i];
        }
    printf("%lld", f[x] * 5ll);
    return 0;
}

//*本题为01背包的一种变式，在“不取”的情况下依然需要转移
//*所以j必须遍历到0（不是1）