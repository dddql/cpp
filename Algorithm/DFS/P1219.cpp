#include <cstdio>
#define M 101

int n,ans,a[M];             //*记录第i行棋子的列数
int b1[M], b2[M], b3[M];    //*判断是否在其他棋子的攻击范围内
//*b1代表列数,b2代表左斜线,b3代表右斜线

void dfs(int x) {
    if(x>n){
        ans++;
        if(ans<=3){
            for (int i = 1; i <= n;i++) 
                printf("%d ", a[i]);
            puts(" ");
        }
        return;
    }
    for (int i = 1; i <= n;i++){    //*枚举列数
        if( b1[i]==0 && b2[x+i]==0 && b3[x-i+2*n-1]==0 ){
            a[x] = i;
            b1[i] = 1, b2[x + i] = 1, b3[x - i + 2 * n - 1] = 1;
            dfs(x + 1);
            b1[i] = 0, b2[x + i] = 0, b3[x - i + 2 * n - 1] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(1);
    printf("%d", ans);
    return 0;
}