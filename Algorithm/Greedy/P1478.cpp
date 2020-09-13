#include <cstdio>
#include <algorithm>
using namespace std;

int n, s;
int a, b;
int k, h, ans;
struct apple{
    int x;
    int y;
};
apple l[5050];

bool cmp(apple a,apple b){
    return a.y < b.y;
}

int main()
{
    scanf("%d%d", &n, &s);
    scanf("%d%d", &a, &b);
    h = a + b;
    for (int i = 1; i <= n;i++){
        int tx, ty;
        scanf("%d%d", &tx, &ty);
        if(h<tx)
            continue;
        else{
            ++k;
            l[k].x = tx, l[k].y = ty;
        }
    }
    sort(l + 1, l + k + 1, cmp);
    int i = 1;
    while(s>=l[i].y&&i<=k){
        s -= l[i++].y;
        ans++;
    }
    printf("%d", ans);
    return 0;
}