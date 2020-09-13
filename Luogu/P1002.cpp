#include <cstdio>

int n, m;   //*目标坐标
int x, y;   //*马的坐标
long long f[21][21];
int ctrl[21][21];

int d[9][2] = {{0, 0}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void cal(int n, int m){
    //*记录控制点
    for (int i = 0; i <= 8;i++){
        int tmpx = x + d[i][0];
        int tmpy = y + d[i][1];
        if (tmpx >= 0 && tmpx <= n && tmpy >= 0&&tmpy <= m)
            ctrl[tmpx][tmpy] = 1;
    }

    //*判断原点
    if(ctrl[0][0]==0)
        f[0][0] = 1;

    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(ctrl[i][j])
                continue;
            if(i)   //*不在y轴上（上方还有点）
                f[i][j] += f[i - 1][j];
            if(j)   //*不在x轴上（左边还有点）
                f[i][j] += f[i][j - 1];
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    cal(n, m);
    printf("%lld", f[n][m]);
    return 0;
}