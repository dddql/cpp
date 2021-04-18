#include <cstdio>

int n, m, t;
int a[1000];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        scanf("%d", &t);
        a[t]++;
    }
    for (int i = 1; i <= n;i++)
        while(a[i]--)
            printf("%d ", i);
    return 0;
}