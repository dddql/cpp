#include <cstdio>

int n, p;
int a[8], rslt[8];
int t[8];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 7;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++){
        p = 0;
        for (int j = 1; j <= 7;j++)
            scanf("%d", &t[j]);
        for (int m = 1; m <= 7;m++){
            for (int n = 1; n <= 7;n++)
                if(t[n]==a[m])
                    p++;
        }
        rslt[p]++;
    }
    for (int i = 7; i >= 1;i--)
        printf("%d ", rslt[i]);
    return 0;
}