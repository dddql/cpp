#include <cstdio>

int n,a;
int sum;
int maxn=-1, minn=11;
float ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a);
        if (a>maxn) maxn=a;
        if (a<minn) minn=a;
        sum+=a;
    }
    ans=(sum-maxn-minn)*1.0/(n-2);
    printf("%.2f", ans);
    return 0;
}