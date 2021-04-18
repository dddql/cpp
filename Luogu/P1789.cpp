#include <cstdio>

const int maxn = 105;

int n, m, k, ans;
int map[maxn][maxn];

int dx1[13] = {2,0,-2,0,1,1,1,0,0,0,-1,-1,-1};
int dy1[13] = {0,2,0,-2,0,1,-1,1,0,-1,0,1,-1};
int dx2[25] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
int dy2[25] = {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};

void light_torch(int x,int y){
    for (int i = 0; i < 13;i++){
        int tx = x + dx1[i], ty = y + dy1[i];
        tx = tx < 0 ? 0 : tx, ty = ty < 0 ? 0 : ty;
        map[tx][ty] = 1;
    }
}

void light_stone(int x,int y){
    for (int i = 0; i < 25;i++){
        int tx = x + dx2[i], ty = y + dy2[i];
        tx = tx < 0 ? 0 : tx, ty = ty < 0 ? 0 : ty;
        map[tx][ty] = 1;
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        light_torch(x, y);
    }
    for (int i = 1; i <= k;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        light_stone(x, y);
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            if(map[i][j] == 0)
                ans++;
    printf("%d", ans);
    return 0;
}