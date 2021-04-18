//*Longest Common Subsequence
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e5+5;

int n;
int dp[maxn];
int a[maxn], b[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (a[i] == b[j])
                dp[j] = dp[j - 1] + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
        }
    printf("%d", dp[n]);
    return 0;
}