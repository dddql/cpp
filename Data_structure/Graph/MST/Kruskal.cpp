#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5e3 + 10;
const int maxm = 2e5 + 10;

struct edge{
    int u;
    int v;
    int w;
} e[maxm];

struct ufset{
    int fa[maxn], size[maxn];

    void build(int n){
        for (int i = 1; i <= n;i++)
            fa[i] = i, size[i] = 1;
    }

    int find(int x){
        if(fa[x]==x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void join(int a, int b){
        int f1 = find(a);
        int f2 = find(b);
        if(size[f1]<size[f2]){
            fa[f1] = fa[f2];
            size[f2] += size[f1];
        }
        else{
            fa[f2] = f1;
            size[f1] += size[f2];
        }
    }
} s;

int n, m, ans, cnt;

bool cmp(edge a,edge b){
    return a.w < b.w;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i].u = u, e[i].v = v, e[i].w = w;
    }
    sort(e + 1, e + m + 1, cmp);
    s.build(n);

    for (int i = 1; i <= m;i++){
        int x = s.find(e[i].u);
        int y = s.find(e[i].v);
        if(x==y)
            continue;
        cnt++;
        s.join(x, y);
        ans += e[i].w;
    }

    if(cnt==n-1)
        printf("%d", ans);
    else
        printf("orz");
    return 0;
}