#include <cstdio>

int n;
int sum;

void work(int n) {
    sum++;
    for (int i = 1; i <= n / 2;i++)
        work(i);
}
int main()
{
    scanf("%d", &n);
    work(n);
    printf("%d", sum);
    return 0;
}