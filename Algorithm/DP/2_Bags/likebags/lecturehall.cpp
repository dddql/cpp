#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 13;

struct spe{
    int p;
    int k;
    int len;
} a[maxn];

int n, t;
int f[maxn];

bool cmp(spe a,spe b){
    if(a.k==b.k)
        return a.p < b.p;
    return a.k < b.k;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d", &a[i].p, &a[i].k);
        a[i].len = a[i].k - a[i].p;
        t = max(t, a[i].k);
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n;i++)
        for (int j = t; j >= a[i].k;j--)
            f[j] = max(f[a[i].p] + a[i].len, f[j]);
    printf("%d", f[t]);
    return 0;
}