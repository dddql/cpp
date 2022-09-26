#include <cstdio>
#include <vector>


const int maxn = 1e4 +10;
const int maxm = 5e4 + 10;

struct edge{
    int v;
    int m;
};

std::vector<edge> e[maxn];



int n, m;


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        int u, v, m;
        scanf("%d%d%d", &u, &v, &m);
        e[u].push_back((edge){v, m});
        e[v].push_back((edge){u, m});
    }
    scanf("%d", &q);
    for (int i = 1; i <= q;i++){
        int x, y;
        scanf("%d%d", &x, &y);
    }
        return 0;
}