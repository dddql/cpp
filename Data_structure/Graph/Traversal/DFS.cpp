#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1000005;

vector<int> e[maxn];
queue<int> q;
bool visit[maxn];

int n, m;

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9'){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x*f;
}

void dfs(int x){
    visit[i] = true;
    printf("%d ", x);
    for (int i = 0; i < e[x].size();i++)
        if(!visit[e[x][i]])
            dfs(e[x][i]);
}

void bfs(){
    visit[1] = true;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < e[x].size();i++)
            if(!visit[e[x][i]]){
                visit[e[x][i]] = true;
                q.push(e[x][i]);
            }
    }
}

int main()
{
    n = read();
    m = read();

    for (int i = 1; i <= m;i++){
        int u = read();
        int v = read();
        e[u].push_back(v);
    }

    for (int i = 1; i <= n;i++)
        sort(e[i].begin(), e[i].end());

    visit[1] = true;
    dfs(1);

    printf("\n");
    memset(visit, 0, sizeof(visit));

    bfs();

    return 0;
}