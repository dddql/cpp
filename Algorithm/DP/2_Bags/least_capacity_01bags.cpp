#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e3;
const int INF = 0x3f3f3f3f;

int n, M;
int w[maxn], c[maxn], f[maxn];

int main(){
    scanf("%d%d", &M,&n);
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &w[i], &c[i]);
    for (int i = 1; i <= n;i++)
        for (int j = M; j >= w[i];j--){
            if(j+w[i]>=M)
                f[M] = min(f[M], f[j] + c[i]);
            else
                f[j + w[i]] = min(f[j + w[i]], f[j] + c[i]);
        }
    printf("%d", f[M]-INF);
    return 0;
}