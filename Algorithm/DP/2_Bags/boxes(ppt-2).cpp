#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e4+5;

int V, n;
int v[maxn];
int f[maxn];

int main(){
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n;i++)
        for (int j = V; j >= v[i];j--)
            f[j] = max(f[j], f[j - v[i]] + v[i]);
    printf("%d", V - f[V]);
    return 0;
}