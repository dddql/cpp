#include <cstdio>

const int M = 998244353;
int num, n;
long long s[31][31];
/*
long long cal(int n, int k) {
    if(n==k)
        return 1;
    if(k==1)
        return 1;
    if(k==0)
        return 0;
    
}
*/
long long cal(int n) {
    for (int i = 1; i <= n;i++){
        s[i][1] = 1;
        s[i][i] = 1;
    }
    for (int i = 2; i <= n;i++){
        for (int j = i+1; j <= k;j++){
            s[i][j] = s[i - 1][j - 1] + j * s[i - 1][j];
        }
    }
    return s[n][k];
}
int main()
{
    scanf("%d", &num);
    for (int i = 1; i <= n;i++){
        scanf("%d", &n);
        printf("%lld", cal(n)%M);
    }
    return 0;
}