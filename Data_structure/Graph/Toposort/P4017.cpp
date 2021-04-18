#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 5005;
const int mod = 80112002;

vector<int> e[maxn];
queue<int> q;

int in[maxn], out[maxn], num[maxn];
int n, m, ans;

void build(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        out[u]++, in[v]++;
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size();i++){
            int next = e[x][i];
            in[next]--;
            num[next] = (num[next] + num[x]) % mod;
            if(!in[next])
                q.push(next);
        }
    }
}

int main()
{
    build();

    for (int i = 1; i <= n;i++){
        if(!in[i]){
            num[i] = 1;
            q.push(i);
        }
    }

    bfs();

    for (int i = 1; i <= n; i++)
        if(!out[i])
            ans = (ans + num[i]) % mod;

    printf("%d", ans);

    return 0;
}