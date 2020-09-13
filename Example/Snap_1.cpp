#include <cstdio>
#include <cstdlib>

int n, T,sum;
bool flag[1000];
struct item{
    int num;
    int w;
};
item w[1001];

void dfs(int index,int T) {
    if(T==0){
        for (int i = 1; i <= n;i++)
            if(flag[i])
                printf("%d %d\n", w[i].num, w[i].w);
        exit(0);        //*这里只需要找到一个解，所以直接退出程序
    }
    for (int i = index; i <= n;i++){
        if(T>=w[i].w){
            flag[i] = true;
            dfs(i + 1, T - w[i].w);
            flag[i] = false;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n;i++){
        scanf("%d", &w[i].w);
        w[i].num = i;
    }
    dfs(1,T);
    printf("Not Found.\n");
    return 0;
}