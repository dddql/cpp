#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10005;

struct queue{
    int a[1005];
    int head = 1, tail = 0;

    void push(int x){
        a[++tail] = x;
    }

    void pop(){
        head++;
    }

    int front(){
        return a[head];
    }

    int size(){
        return tail - head + 1;
    }

    bool empty(){
        return head>tail;
    }
};

vector<int> e[maxn];
queue q;

int n, m, ans;
int in[maxn];
int t[maxn], cost[maxn];

void build(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        int num;
        scanf("%d%d", &num, &t[i]);
        int anc;
        while(scanf("%d",&anc)&&anc){
            e[anc].push_back(num);
            in[num]++;
        }
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size();i++){
            int next = e[x][i];
            in[next]--;
            if(!in[next])
                q.push(next);
            cost[next] = max(cost[next], cost[x] + t[next]);
        }
    }
}

int main()
{
    freopen("P1113_2.in", "r", stdin);

    build();

    for (int i = 1; i <= n;i++)
        if(!in[i]){
            q.push(i);
            cost[i] = t[i];
        }

    bfs();

    for (int i = 1; i <= n;i++)
        ans = max(ans, cost[i]);

    printf("%d", ans);
    return 0;
}