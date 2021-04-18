#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int maxn = 1e3;
const int INF = 0x3f3f3f3f;

struct edge{
    int to;
    int length;
};


vector<edge> e[maxn];
pair<int, int> dot[maxn];

int n;
int map[maxn][maxn];

int main()
{
    scanf("%d", &n);
    for (register int i = 1;i<=n;i++){
        scanf("%d%d", &dot[i].first, &dot[i].second);
        
    }
        return 0;
}

