#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e6 + 1;
const int maxm = 2e6 + 1;
const int INF = 0x7f7f7f7f;
const int MOD = 1e5 + 3;

vector<int> G[maxn];
queue<int> Q;

int dep[maxn], cnt[maxn];
bool vis[maxn];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);      //*由于vector的性质，存重边无需其他操作
        G[y].push_back(x);
    }
    dep[1] = 0, vis[1] = true, cnt[1] = 1;
    Q.push(1);
    while (!Q.empty()){
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); i++){
            int t = G[x][i];
            if (!vis[t]){
                vis[t] = true;
                dep[t] = dep[x] + 1;
                Q.push(t);
            }
            if (dep[t] == dep[x] + 1)
                cnt[t] = (cnt[t] + cnt[x]) % MOD;
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d\n", cnt[i]);
    return 0;
}