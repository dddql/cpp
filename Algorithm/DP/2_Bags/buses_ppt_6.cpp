#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 16;
const int INF = 0x3f3f3f3f;

int a[11], f[maxn];
int n;

int main(){
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= 10;i++)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    /*
    for (int i = 1; i <= 10;i++){
        int minx = INF;
        for (int j = i-1; j >= 1 ; j--)
            minx = min(minx, f[i - j] + f[j]);
        f[i] = min(minx,a[i]);
    }
    for (int i = 11; i <= n; i++){
        int minx = INF;
        for (int j = 1; j <= 10 ; j++)
            minx = min(minx, f[i - j] + f[j]);
        f[i] = minx;
    }
    */
    for (int i = 1; i <= 10;i++)
        for (int j = i; j <= n;j++)
            f[j] = min(f[j], f[j - i] + a[i]);
    printf("%d", f[n]);
    return 0;
}