#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 1e3;
const int INF = 0x3f3f3f3f;

struct edge{
    int y;
    double z;
};
vector<edge> e[maxn];
int n, m,a,b;
int dis[maxn], flag[maxn];


void dij(int a,int b){
    dis[a] = 1;
    for (int i = 1; i <= n;i++){
        int min = INF, k = 0;
        for (int j = 1; j <= n; j++)
            if(!flag[j]&&min>e[i][j].z){
                k = j;
                min = e[i][j].z;
            }

        if(k==b)
            return;

        flag[k] = true;
        for (int j = 0; j < e[k].size();j++)
            if(dis[j]<dis[k]*e[k][j].z)
                dis[j] = dis[k] * e[k][j].z;
    }
}

int main(){
    memset(dis, 0, sizeof(dis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int x, y, t;
        scanf("%d%d%lf", &x, &y, &t);
        e[x].push_back((edge){y, (double)(100-t)/100});
    }
    scanf("%d%d", &a, &b);
    dij(a,b);
    printf("%.8lf", (double)100 / dis[b]);
    return 0;
}
