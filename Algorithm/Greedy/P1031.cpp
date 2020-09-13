#include <cstdio>

int n,avg,step;
int a[105];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
        avg += a[i];
    }
    avg /= n;
    for (int i = 1; i < n;i++){
        if(a[i]==avg)
            continue;
        a[i] < avg ? a[i + 1] -= avg - a[i] : a[i + 1] += a[i] - avg;
        a[i] = avg;
        step++;
    }
    printf("%d", step);
    return 0;
}