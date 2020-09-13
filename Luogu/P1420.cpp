#include <cstdio>

int n;
int a[10001];
int ans=1,maxn=0;

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for (int i=1;i<n;i++){ 
        if (a[i+1]-a[i]==1) ans++;
        else ans=1;
        if (ans>maxn) maxn=ans;
    }
    printf("%d", maxn);
    return 0;
}