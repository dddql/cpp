#include <cstdio>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int t = (c * 60 + d) - (a * 60 + b);
    printf("%d %d", t / 60, t % 60);
    return 0;
}