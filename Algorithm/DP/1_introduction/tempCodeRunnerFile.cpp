#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e4+5;

int t, m;
int a[maxn], b[maxn];
int f[maxn];


int main(){
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m;i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= m;i++)
        for (int j = a[i]; j <= t;j++)
            f[j] = max(f[j - 1], f[j - a[i]] + b[i]);
    printf("%d", f[t]);
    return 0;
}