//*最长不下降子序列
//*这里只求了长度
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10;

int n;
int a[maxn],f[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++){
        int maxt = 1;
        for (int j = 1; j <= i;j++){
            if(a[i]>a[j])
                maxt = max(maxt, f[j] + 1);
        }
        f[i] = maxt;
    }
    printf("%d", f[n]);
    return 0;
}