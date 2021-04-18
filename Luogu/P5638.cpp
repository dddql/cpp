#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e6+10;

long long n, k;
long long a[maxn];
long long sum, sum_k, maxk, ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i < n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
        if(i<=k)
            sum_k += a[i];
        if(i>k)
            sum_k = sum_k - a[i - k] + a[i];
        maxk = max(maxk, sum_k);
    }
    ans = sum - maxk;
    printf("%lld", ans);
    return 0;
}