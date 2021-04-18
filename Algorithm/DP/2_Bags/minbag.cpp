//*尽量装满背包情况下的最小价值
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 11;

int m,n;
int w[maxn],c[maxn];
int f[maxn];

int main(){
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=n;i++)
        scanf("%d%d",&w[i],&c[i]);
    for(int i = 1;i<=n;i++)
        for(int j = m;j>=w[i];j--)
            f[j] = min(f[j],f[j-w[i]]+c[i]);

    int i = m;
    while (f[i] == INF)
        i--;

    printf("%d", f[i]);
    return 0;
}

/*
背包问题：
求最大：f[j]足够小。
求最小：f[1~m]足够大,f[0]足够小。
*/