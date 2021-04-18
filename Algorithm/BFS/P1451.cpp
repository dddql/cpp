#include <cstdio>
#include <string>
#include <queue>
using namespace std;

queue< pair<int, int> > Q;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int n, m, ans;
string s;
bool a[105][105];
bool visit[105][105];

void init(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%s", s.c_str());
        for (int j = 0; j < m;j++){
            if(s[j]!='0')
                a[i][j] = true;
        }
    }
}

bool in_range(int x,int y){
    return x >= 1 && x <= n && y >= 0 && y < m;
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
            int sx = tx + dx[i], sy = ty + dy[i];
            if(in_range(sx,sy)&&a[sx][sy]&&!visit[sx][sy]){
                Q.push(make_pair(sx, sy));
                visit[sx][sy] = true;
            }
        }
    }
}

int main()
{
    init();

    for (int i = 1; i <= n;i++){
        for (int j = 0; j < m;j++){
            if(a[i][j]&&!visit[i][j])
                bfs(i, j);
        }
    }

    printf("%d", ans);

    return 0;
}