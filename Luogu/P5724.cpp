#include <cstdio>
#include <algorithm>
using namespace std;

int n,ans;
int a[100];

int main()
{
    scanf("%d", &n);
    for (int i=0;i<n;i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    ans=a[n-1]-a[0];
    printf("%d", ans);
    return 0;
}