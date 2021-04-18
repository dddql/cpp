#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 50;
const int maxm = 1e3;

int n, m;
int c[maxn];
int f[maxn];

int main(){
    scanf("%d%d", &n, &m), f[0] = 1;
    for (int i = 1; i <= n;i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n;i++)
        for (int j = c[i]; j <= m;j++)
            f[j] = f[j] + f[j - c[i]];
    printf("%d", f[m]);
    return 0;
}