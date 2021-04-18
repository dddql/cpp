//*并查集模板
//*P1551 亲戚
#include <cstdio>
#define maxn 5050

struct set{
    int fa[maxn];

    int find(int x){    //*找到x的祖先
        if(x==fa[x])
            return x;
        return fa[x] = find(fa[x]);    //*递归查找的同时更新当前节点祖先
    }

    void join(int a, int b){
        int f1 = find(a);
        int f2 = find(b);
        if(f1!=f2)
            fa[f1] = f2;
    }
} s;

int n, m, p;
int x, y;

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n;i++)
        s.fa[i] = i;
    for (int i = 1; i <= m;i++){
        scanf("%d%d", &x, &y);
        s.join(x, y);
    }
    for (int i = 1; i <= p;i++){
        scanf("%d%d", &x, &y);
        if(s.find(x)==s.find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}