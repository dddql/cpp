#include <cstdio>
#include <algorithm>
const int maxn = 1e3;

int n, sum;
int a[maxn], f[maxn];

int main(){
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i <= n;i++)
        for (int j = sum / 2; j >= a[i];j--)
            f[j] = f[j] + f[j - a[i]] ;
    if(sum&1)
        printf("0");
    else
        printf("%d", f[sum / 2]/2);
    return 0;
}