#include <cstdio>

int n, p;
int sur[100000];

int cal(int n, int p) {
    for (int i = 1; i <= p;i++)
        sur[i] = i * 2;
    for (int i = p + 1; i <= n;i++)
        sur[i] = sur[i - 1] + i;
    return sur[n];
}
int main()
{
    scanf("%d%d", &n, &p);
    printf("%d", cal(n, p));
    return 0;
}