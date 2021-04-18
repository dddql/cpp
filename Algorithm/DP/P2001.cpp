#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 2e6 + 1;
const long long max_m = 2e7+1;
const long long INF = 0xffffff;

int a[max_n], f[max_m];
int n, m;

int count(int m);

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%d", count(m));
    return 0;
}

int count(int m){
    f[0] = 0;

    for (int i = 1; i <= m;i++){
        int cost = INF;
        for (int j = 1; j <= n;j++){
            if (i - a[j] >= 0)
                cost = min(cost, f[i - a[j]]) + 1;
            else
                break;
        }
        f[i] = cost;
    }

    return f[m];
}