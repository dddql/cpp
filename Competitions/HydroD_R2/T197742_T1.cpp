#include <cstdio>

int maxn = 1e6 + 5;

int n,a,b;

struct goods{
    int v;
    int p;
    char c;
} g[maxn];

int main(){
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n;i++)
        scanf("%d%d%c", &g[i].v, &g[i].p, &g[i], c);
    
        return 0;
}