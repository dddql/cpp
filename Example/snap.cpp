#include <cstdio>

int n, T,sum;
struct item{
    int num;
    int w;};
item w[1001];

void load(int n,int T) {
    sum = 0;
    if(T<0||n<=0)
        return;
    for (int i = 1; i <= n;i++){
        sum += w[i].w;
        if(sum+w[i+1].w>T)
            load(i, T - w[i].w);
        if(sum+w[i].w==T)
            printf("%d %d\n", w[i].num, w[i].w);
    }
}
main()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n;i++){
        scanf("%d", &w[i].w);
        w[i].num = i;
    }
    load(n,T);
    return 0;
}