#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e4 + 5;
const int maxt = 1e7 + 5;

int t, m;
int a[maxn], b[maxn];
int f[maxt];

signed main(){
    scanf("%lld%lld", &t, &m);
    for (int i = 1; i <= m;i++)
        scanf("%lld%lld", &a[i], &b[i]);
    for (int i = 1; i <= m;i++)
        for (int j = a[i]; j <= t;j++)
            f[j] = max(f[j], f[j - a[i]] + b[i]);
    printf("%lld", f[t]);
    return 0;
}