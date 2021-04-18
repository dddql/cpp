#include <cstdio>

const int maxn = 202;

int n;
int T, t, c;
int x = 1, y = 1;
int map[maxn][maxn];

int main(){
    scanf("%d", &n);
    while(T<n*n){
        scanf("%d", &t);
        T += t;
        for (int i = 1; i <= t;i++){
            map[x][y++] = c;
            if(y>n)
                x++, y = 1;
        }
        c ^= 1;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            printf("%d", map[i][j]);
        printf("\n");
    }
    return 0;
}