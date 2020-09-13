#include <cstdio>
#define maxn 1050

int n;
int a[maxn][maxn];

int main()
{
    scanf("%d", &n);
    a[1][1] = 1;
    for (int i = 2; i <= n;i++)
        for (int j = 1; j <= i;j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}