#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+5;

int M,N;
int p[maxn], t[maxn];
int f[maxn];

int main(){
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N;i++)
        scanf("%d%d", &p[i], &t[i]);
    for (int i = 1; i <= N;i++)
        for (int j = t[i]; j <= M;j++)
            f[j] = max(f[j], f[j - t[i]] + p[i]);
    printf("%d", f[M]);
    return 0;
}