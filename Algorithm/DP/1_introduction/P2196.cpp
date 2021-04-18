#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e3;
const int INF = 0x3f3f3f3f;

vector<int> e[maxn];

int n, ans;
int a[maxn], f[maxn], pre[maxn];
bool visit[maxn];

bool check(int x){
    bool flag = false;
    for(int i =0;i<e[x].size();i++)
        if(!visit[e[x][i]])
            flag = true;
    return flag;
}

void print(int x){
    if(pre[x]==-1){
        printf("%d",x);
        return;
    }
    printf("%d ", x);
    print(pre[x]);
}

int dfs(int x){
    if(f[x])
        return f[x];
    if(!check(x))
        return f[x] = a[x];
    visit[x] = true;
    for (int i = 0; i < e[x].size();i++)
        if(!visit[e[x][i]]&&e[x][i]>x){     //*题目规定只能向“下”挖，即地窖编号
            int tmp = dfs(e[x][i]);         //*只能从小到大
            if(tmp + a[x]>f[x])
                pre[x] = e[x][i];
            f[x] = max(tmp + a[x], f[x]);
        }
    return f[x];
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]), pre[i] = -1;

    for (int i = 1; i < n;i++)
        for (int j = i + 1; j <= n;j++){
            int flag = 0;
            scanf("%d", &flag);
            if(flag)
                e[i].push_back(j);
        }

    int t;
    for (int i = 1; i <= n;i++){
        memset(visit, 0, sizeof(visit));    //*记得多次dfs后多次清除标记！
        ans = max(dfs(i), ans);
    }
    for (int i = 1; i <= n;i++)
        if(f[i]==ans)
            t = i;

    print(t), printf("\n");
    printf("%d", ans);
    return 0;
}