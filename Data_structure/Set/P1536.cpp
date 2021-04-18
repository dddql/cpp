#include <cstdio>
#define maxn 1050

int n, m, x, y;
int ans;

struct set{
    int r[maxn];

    int find(int x){
        if(x==r[x])
            return x;
        return r[x] = find(r[x]);
    }

    void join(int a,int b){
        int r1 = find(a);
        int r2 = find(b);
        if(r1!=r2){
            r[r1] = r2;
            ans--;
        }
    }
} s;

int main()
{
    while(1){
        scanf("%d", &n);
        if(n==0)
            return 0;
        scanf("%d", &m);
        ans = n;
        for (int i = 1; i <= n;i++)
            s.r[i] = i;
        for (int i = 1; i <= m;i++){
            scanf("%d%d", &x, &y);
            s.join(x, y);
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}