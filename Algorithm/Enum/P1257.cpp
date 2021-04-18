#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;

int n;
double ans = 123456789.0;

struct point{
    int x, y;
} a[maxn];

double dis(point a,point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 1; i <= n;++i)
        for (int j = i + 1; j <= n;++j)
            ans = min(ans, dis(a[i], a[j]));
    printf("%.4lf", ans);
    return 0;
}