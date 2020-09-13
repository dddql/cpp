#include <cstdio>

int N, M;
int ans,a[5];

void dfs(int index,int k) {
    if(k==0){
        ans++;
        return;
    }
    for (int i = index; i <= N;i++){
        if(k>=a[i])
            dfs(i + 1, k - a[i]);
    }
}
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N;i++)
        scanf("%d", &a[i]);
    dfs(1, M);
    printf("%d", ans);
    return 0;
}