//*多重背包
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 505;
const int maxm = 6e3 + 5;
const int maxs = 11;

int n,m;
int v[maxn], w[maxn], s[maxs];//价值，重量，个数
int f[maxn];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    for (int i = 1; i <= n;i++)
        for (int j = m; j >= w[i];j--)
            for (int k = 0; k <= s[i];k++)
                if(j>=k*w[i])
                    f[j] = max(f[j], f[j - k*w[i]] + k*v[i]);
    printf("%d", f[m]);
    return 0;
}