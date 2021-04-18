#include <cstdio>
#include <queue>
using namespace std;

queue< pair<int, int> > Q;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int n, m, ans;
int a[105][105];
bool visit[105][105];

void init(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            scanf("%d", &a[i][j]);
}

void bfs(int x,int y){
    ans++;

    Q.push(make_pair(x,y));
    visit[x][y] = true;
    while(!Q.empty()){
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4;i++){
            if(a[tx+dx[i]][ty+dy[i]]&&!visit[tx+dx[i]][ty+dy[i]]){
                Q.push(make_pair(tx + dx[i], ty + dy[i]));
                visit[tx + dx[i]][ty + dy[i]] = true;
            }
        }
    }
}

int main()
{
    init();

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(a[i][j]&&!visit[i][j])
                bfs(i, j);
        }
    }

    printf("%d", ans);

    return 0;
}