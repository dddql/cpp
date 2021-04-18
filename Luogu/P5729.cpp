#include <cstdio>

const int maxn = 25;

int w, l, h;
int x1, x2, y1, y2, z1, z2;
int q, t;
int map[maxn][maxn][maxn];

int main(){
    scanf("%d%d%d", &l, &w, &h);
    scanf("%d", &q);
    for (int i = 1; i <= q;i++){
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int x = x1; x <= x2;x++)
            for (int y = y1; y <= y2;y++)
                for (int z = z1; z <= z2;z++)
                    map[x][y][z] = 1;
    }
    t = l * w * h;
    for (int x = 1; x <= l;x++)
        for (int y = 1; y <= w;y++)
            for (int z = 1; z <= h;z++)
                if(map[x][y][z] == 1)
                    t--;
    printf("%d", t);
    return 0;
}