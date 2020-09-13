#include <cstdio>

long long n, x, ans;
int a[200500];

int main()
{
    scanf("%lld%lld", &n, &x);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
        if(a[i]>x){
            ans += a[i] - x;
            a[i] = x;
        }
    }
    for (int i = 2; i <= n;i++){
        if(a[i]+a[i-1]>x){
            ans += a[i - 1] + a[i] - x;
            a[i] = x - a[i - 1];
        }
    }
    printf("%lld", ans);
    return 0;
}