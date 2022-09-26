//*并查集模板
//*P1551 亲戚
#include <cstdio>
#define maxn 5050

struct set{
    int fa[maxn], size[maxn];

    void build(int n){
        for (int i = 1; i <= n;i++)
            fa[i] = i, size[i] = 1;
    }

    int find(int x){
        if(x == fa[x])
            return x;
        return fa[x] = find(fa[x]);     //*路径压缩
    }

    void join(int a,int b){
        int f1 = find(a);
        int f2 = find(b);
        if(size[f1]<size[f2]){          //*按秩合并（启发式合并）
            fa[f1] = f2;
            size[f2] += size[f1];
        }
        else{
            fa[f2] = f1;
            size[f1] += size[f2];
        }
    }
} s;

int n, m, p;
int x, y;

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    s.build(n);
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