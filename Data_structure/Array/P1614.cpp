#include <cstdio>
#define maxn 3050

int n, m;
int ans, min = 1e7;
int a[maxn];
int sum[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    if(m>n)
        printf("%d", sum[n]);
    else{
        for (int i = m; i <= n;i++){
                ans = sum[i] - sum[i - m];
                if(ans<min)
                    min = ans;
            }
        printf("%d", min);
    }
    return 0;
}