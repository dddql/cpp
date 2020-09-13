#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, ans;
struct farmer{
    int p;
    int a;
} f[5050];

bool cmp(farmer a,farmer b){
    return a.p < b.p;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++)
        scanf("%d%d", &f[i].p, &f[i].a);
    sort(f + 1, f + m + 1, cmp);
    int i;
    for (i = 1; i <= m;i++){
        if(n>=f[i].a){
            ans += f[i].p * f[i].a;
            n -= f[i].a;
        }
        else
            break;
    }
    ans += n * f[i].p;
    printf("%d", ans);
    return 0;
}