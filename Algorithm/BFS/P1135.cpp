#include <cstdio>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
pair<int, int> now;

int n, a, b;
int k[205];
bool visit[205];

void bfs(int a,int b){
    q.push(make_pair(a, 0));
    visit[a] = true;
    while(!q.empty()){
        now = q.front();
        q.pop();

        if(now.first==b)
            break;
        for (int i = -1; i <= 1;i+=2){
            int tx = now.first + k[now.first] * i;
            if (tx >= 1&&tx <= n&&!visit[tx]){
                q.push(make_pair(tx, now.second+1));
                visit[tx] = true;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n;i++)
        scanf("%d", &k[i]);

    bfs(a, b);

    if(now.first==b)
        printf("%d", now.second);
    else
        printf("-1");
    return 0;
}