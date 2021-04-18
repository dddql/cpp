#include <cstdio>

const int maxn = 100;

int m, n, p;
int tot, ans;
int a[maxn];

int main(){
    scanf("%d%d%d", &m, &n, &p);
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            for (int k = 1; k <= p;k++){
                tot = i + j + k;
                a[tot]++;
            }
    int max = -1;
    for (int i = 1; i <= m + n + p;i++)
        if(max<a[i]){
            max = a[i];
            ans = i;
        }
    printf("%d", ans);
    return 0;
}