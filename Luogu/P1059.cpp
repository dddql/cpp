#include <cstdio>

int N[1001];
int n, t, sum;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        if (N[t] != 0)
            continue;
        else
        {
            N[t]++;
            sum++;
        }
    }
    printf("%d\n", sum);
    for (int i = 1; i <= 1000; i++)
    {
        if (N[i] != 0)
            printf("%d ", i);
    }
    return 0;
}