#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 16;

int n,m;
int a[maxn][maxn], f[maxn][maxn];
int b[maxn][maxn], M[maxn];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            int maxt = 0;
            for (int k = 0; k <= j; k++){
                if(maxt<f[i - 1][k] + a[i][j - k]){
                    maxt = f[i - 1][k] + a[i][j - k];
                    b[i][j] = j - k;
                }
            }
            f[i][j] = maxt;
        }
    }
    printf("%d\n", f[n][m]);
    int t = n;
    for (int i = 1; i <= n; i++){
        M[i] = b[t][m];
        m -= b[t--][m];
    }
    for (int i = 1; i <= n;i++)
        printf("%d %d\n", i, M[i]);
    return 0;
}