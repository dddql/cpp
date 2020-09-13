#include <cstdio>

int n, m;
int a[105][25];
float score[105];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        int sum = 0, min = 11, max = -1;
        for (int j = 1; j <= m;j++){
            scanf("%d", &a[i][j]);
            sum += a[i][j];
            if(min>a[i][j])
                min = a[i][j];
            if(max<a[i][j])
                max = a[i][j];
        }
        score[i] = 1.0 * (sum - min - max) / (m - 2);
    }
    float max = -1;
    for (int i = 1; i <= n;i++)
        if(score[i]>max)
            max = score[i];
    printf("%.2f", max);
    return 0;
}