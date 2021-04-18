/*#include <cstdio>


void floyd(){
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                dis[i][j] = (dis[i][k] + dis[k][j]);
}
int main()
{
    
    return 0;
}*/

#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

const int maxn = 105;

struct dot{
    int x;
    int y;
} a[maxn];
int n, m, s, t;
float dis[maxn][maxn];

float ask_dis(dot a,dot b){
    float d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return d;
}

void floyd(){
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][s])
                    dis[i][j] = dis[i][k] + dis[k][s];
}
int main(){
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        int x, y;
        scanf("%d%d", a[i].x, a[i].y);
    }
    scanf("%d", &m);
    for (int k = 1; k <= m;k++){
        int i, j;
        scanf("%d%d", &i, &j);
        dis[i][j] = ask_dis(a[i], a[j]);
    }
    floyd();
    scanf("%d%d", &s, &t);
    printf("%.2f", dis[s][t]);
    return 0;
}