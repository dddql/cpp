//!这道题也是DP！！！
//*01背包
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3;

int M,N;
int w[maxn], c[maxn];
int f[maxn];

int main(){
    scanf("%d%d",&M,&N);
    for (int i = 1; i <= N;i++)
        scanf("%d%d", &w[i], &c[i]);
    for (int i = 1; i <= N;i++)
        for (int j = M; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + c[i]);
    printf("%d", f[M]);
    return 0;
}