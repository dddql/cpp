#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 405;
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

queue<pair<int, int> > q;
int ans[maxn][maxn];
int n, m, sx, sy;

void init(){
    memset(ans, -1, sizeof(ans));
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    q.push(make_pair(sx, sy));
    ans[sx][sy] = 0;
}

void bfs(){
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 8;i++){
            int x = tx + dx[i];
            int y = ty + dy[i];

            if(x<1||x>n||y<1||y>m||ans[x][y]!=-1)
                continue;
            else{
                ans[x][y] = ans[tx][ty] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

void print(){
    for (int i = 1; i <= n;i++,printf("\n"))
        for (int j = 1; j <= m;j++)
            printf("%-5d", ans[i][j]);
}

int main()
{
    init();

    bfs();

    print();

    return 0;
}