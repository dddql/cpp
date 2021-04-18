#include <cstdio>
#include <queue>
using namespace std;

queue< pair<int, int> > Q;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, ans;
char a[105][105];
bool visit[105][105];

void init(){
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            scanf("%c", &a[i][j]);
        getchar();
    }
}

bool in_range(int x,int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(int x,int y){
    ans++;

    Q.push(make_pair(x,y));
    visit[x][y] = true;
    while(!Q.empty()){
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop();

        for (int i = 0; i < 8;i++){
            int sx = tx + dx[i];
            int sy = ty + dy[i];
            if(in_range(sx,sy)&&!visit[sx][sy]){
                visit[sx][sy] = true;
                if(a[sx][sy]=='W')
                    Q.push(make_pair(sx, sy));
            }
        }
    }
}

int main()
{
    init();

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(a[i][j]=='W'&&!visit[i][j])
                bfs(i, j);
        }
    }

    printf("%d", ans);

    return 0;
}