#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3+10;

struct road{
    int x, y, t;
} r[maxn];

struct set{
    int fa[maxn], size[maxn];

    void init(int n){
        for (int i = 1; i <= n;i++)
            fa[i] = i, size[i] = 1;
    }

    int find(int x){
        if(fa[x]==x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void join(int f1,int f2){
        if(size[f1]<size[f2]){
            fa[f1] = fa[f2];
            size[f2] += size[f1];
        }
        else{
            fa[f2] = fa[f1];
            size[f1] += size[f1];
        }
    }
} s;

int n,m;
int ans, k;

bool cmp(road a,road b){
    return a.t < b.t;
}

int main(){
    scanf("%d%d",&n,&m);
    s.init(n);
    k = n;
    for (int i = 1; i <= m;i++)
        scanf("%d%d%d", &r[i].x, &r[i].y, &r[i].t);
    sort(r + 1, r + n + 1, cmp);
    for (int i = 1; i <= m;i++){
        int f1 = s.find(r[i].x);
        int f2 = s.find(r[i].y);
        if(f1!=f2){
            s.join(f1, f2);
            k--;
            ans = max(ans, r[i].t);
        }
        if(k==1){
            printf("%d", ans);
            break;
        }
    }
    if(k!=1)
        printf("-1");
    return 0;
}