#include <cstdio>

int m, n;
int a[10];

int main(){
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n;i++){
        int x = i;
        while(x){
            int t = x % 10;
            a[t]++;
            x /= 10;
        }
    }
    for (int i = 0; i < 10;i++)
        printf("%d ", a[i]);
    return 0;
}