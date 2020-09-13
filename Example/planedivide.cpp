#include <cstdio>

int n;
int plane[10000];

int cal(int n) {
    plane[1] = 2;
    for (int i = 1; i <= n;i++){
        plane[i + 1] = plane[i] + i * 2;
    }
    return plane[n];
}
int main()
{
    scanf("%d", &n);
    printf("%d", cal(n));
    return 0;
}