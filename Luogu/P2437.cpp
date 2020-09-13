#include <cstdio>

int m, n;
int len = 1;
int cnt[1005][1005];

void cal(int k) {
    for (int i = 1; i <= len;i++)
        cnt[k][i] = cnt[k-1][i] + cnt[k-2][i];
    for (int i = 1; i <= len;i++){
        if(cnt[k][i]>=10){
            cnt[k][i + 1] += cnt[k][i] / 10;
            cnt[k][i] %= 10;
            if(cnt[k][len+1])
                len++;
        }
    }
}
int main()
{
    scanf("%d%d", &m, &n);
    cnt[1][1] = 1;
    cnt[2][1] = 2;
    for (int i = 3; i <= n - m;i++)
        cal(i);
    for (int i = len; i > 0; i--)
        printf("%d", cnt[n - m][i]);
    return 0;
}