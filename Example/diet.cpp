#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k;
int ans;
int t[105];

struct diet{
    int fat;
    int type;
} d[205];
int index[205];

bool cmp(int a,int b){
    return d[a].fat > d[b].fat;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k;i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n;i++){
        scanf("%d%d", &d[i].fat, &d[i].type);
        index[i] = i;
    }
    sort(index + 1, index + n + 1, cmp);
    for (int i = 1; i <= m;i++){
        if(t[d[index[i]].type]){
            ans += d[index[i]].fat;
            t[d[index[i]].type]--;
        }
    }
    printf("%d", ans);
    return 0;
}