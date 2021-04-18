#include <cstdio>

const int maxn = 11;
int n;
int x = 1, y = 1, k = 1;
int map[maxn][maxn];

int main(){
    scanf("%d", &n);
    while(k<=n*n){
        while((y<n&&!map[x][y+1])||k==n*n)
            map[x][y++] = k++;
        while((x<n&&!map[x+1][y])||k==n*n)
            map[x++][y] = k++;
        while((y>1&&!map[x][y-1])||k==n*n)
            map[x][y--] = k++;
        while((x>1&&!map[x-1][y])||k==n*n)
            map[x--][y] = k++;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            printf("%3d", map[i][j]);
        printf("\n");
    }
    return 0;
}