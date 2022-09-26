#include <cstdio>

int ans;

int main()
{
    for (int i = 100; i <= 10000; i += 2)
        ans += i;
    printf("%d", ans);
    return 0;
}