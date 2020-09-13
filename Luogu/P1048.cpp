//!这道题也是DP！！！

#include <cstdio>
#include <algorithm>
using namespace std;

int T, M;
int i,c;

struct herb{
    int t;
    int v;
};
herb a[110];

bool cmp(herb a,herb b){
    return a.v/a.t<b.v/b.t;
}

int main()
{
    scanf("%d%d", &T, &M);
    for ( i = 1; i <= M;i++)
        scanf("%d%d", &a[i].t, &a[i].v);
    sort(a + 1, a + M + 1, cmp);
    i--;
    while(T&&i){
        if(T>=a[i].t){
            T -= a[i].t;
            c += a[i].v;
        }
        i--;
    }
    printf("%d", c);
    return 0;
}