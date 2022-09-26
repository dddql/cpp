#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 4;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

queue<pair<int, int>> Q;

int n, m, ans;
char map[maxn][maxn];
bool visit[maxn][maxn];

void init();
void bfs(int x, int y);
void check_print();

int main()
{
    init();

    check_print();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'O' && !visit[i][j])
            {
                bfs(i, j);
                visit[i][j] = true;
            }

    printf("%d", ans);
    return 0;
}

void init()
{
    memset(map, '0', sizeof(map));
    memset(visit, false, sizeof(visit));

    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%c", &map[i][j]);
        getchar();
    }
}

void bfs(int x, int y)
{
    ans++;

    Q.push(make_pair(x, y));
    visit[x][y] = true;

    while (!Q.empty())
    {
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (map[tx + dx[i]][ty + dy[i]] == 'O' && !visit[tx + dx[i]][ty + dy[i]])
            {
                Q.push(make_pair(tx + dx[i], ty + dy[i]));
                visit[tx + dx[i]][ty + dy[i]] = true;
            }
        }
    }
}

void check_print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}