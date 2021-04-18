#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double ans;
int n;
struct dot{
    int x, y, z;
} d[50050];

inline bool cmp(dot a, dot b){
        return a.z < b.z;
    }

inline double cal(dot a,dot b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d%d%d", &d[i].x, &d[i].y, &d[i].z);
    sort(d + 1, d + n + 1, cmp);
    for (int i = 1; i < n;i++)
        ans += cal(d[i], d[i + 1]);
    printf("%.3lf", ans);
    return 0;
}