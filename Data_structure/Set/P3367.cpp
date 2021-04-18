#include <cstdio>

const int maxn = 10050;

struct set{
    int fa[maxn];

    int find(int x){
        if(x==fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }

    void join(int a,int b){
        int f1 = find(a);
        int f2 = find(b);
        if(f1!=f2)
            fa[f1] = f2;
    }

    void ask(int a,int b){
        if(find(a)==find(b))
            printf("Y\n");
        else
            printf("N\n");
    }
} s;

int N, M;
int Z, X, Y;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N;i++)
        s.fa[i] = i;
    for (int i = 1; i <= M;i++){
        scanf("%d%d%d", &Z, &X, &Y);
        switch(Z){
            case 1:{
                s.join(X, Y);
                break;
            }
            case 2:
                s.ask(X, Y);
        }
    }
    return 0;
}