#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int x, y[10001];
int mid,sum;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &x, &y[i]);
    sort(y + 1, y + n + 1);
    mid = y[(1 + n) / 2];
    for (int i = 1; i <= n;i++)
        sum += abs(y[i] - mid);
    printf("%d", sum);
    return 0;
}