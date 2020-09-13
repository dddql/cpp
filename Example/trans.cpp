#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int t;
int a[10005],sum[10005];

bool cmp(int m, int n){
    return m > n;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n;i++){
        for (int j = i; j < n;j++){
            if(a[j]<a[j+1])
                swap(a[j], a[j + 1]);
            else
                break;
        }
        a[i + 1] = (a[i] + a[i + 1]) / k;
    }
    printf("%d", a[n]);
    return 0;
}