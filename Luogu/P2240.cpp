#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int i;
float ans, T;

struct gold{
    float w;
    float v;
};
gold a[110];

bool cmp(gold a,gold b){
    return a.v/a.w<b.v/b.w;
}

int main()
{
    scanf("%d%f", &N, &T);
    for ( i = 1; i <= N;i++)
        scanf("%f%f", &a[i].w, &a[i].v);
    sort(a + 1, a + N + 1, cmp);
    i--;
    for (; i >= 1;i--){
        if(a[i].w>T)
            break;
        T -= a[i].w;
        ans += a[i].v;
    }
    if(i>=1)
        ans += a[i].v * (T * 1.0 / a[i].w);
    printf("%.2f", ans);
    return 0;
}