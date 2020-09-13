#include <cstdio>

int n, k, x;
int N[10001];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (N[x] != 0)
            continue;
        else
            N[x]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (N[i] != 0)
            k--;
        if (k == 0)
        {
            printf("%d", i);
            return 0;
        }
    }
    if (k != 0)
        printf("NO RESULT");
    return 0;
}