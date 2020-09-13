#include <cstdio>
#include <algorithm>
using namespace std;

int n, b, ans;
int a[6];

int main()
{
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    while(a[1]||a[2]){
        ans += a[1];
        if(a[1]==a[2]){
            b -= n;
            ans++;
            int t = a[1];
            for (int j = 1; j <= n;j++){
                if(t!=1)
                    a[j] -= t - 1;
                else
                    a[j]--;
            }
        }
        else if(a[1]==0){
            if(b<a[2])
                break;
            b -= a[2];
            ans++;
            int t = a[2];
            for (int j = 2; j <= n;j++)
                a[j] -= t;
        }
        else{
            b -= a[1];
            for (int j = 2; j <= n;j++)
                a[j] -= a[1];
        }
        for (int j = 1; j < n; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    }
    printf("%d", ans);
    return 0;
}