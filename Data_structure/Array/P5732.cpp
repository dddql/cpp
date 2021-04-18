#include <cstdio>
#define maxn 65
typedef long long ll;

ll n;
ll a[maxn][maxn];

int main()
{
    scanf("%lld", &n);
    a[1][1] = 1;
    for (ll i = 2; i <= n;i++)
        for (ll j = 1; j <= i;j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= i; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
    return 0;
}