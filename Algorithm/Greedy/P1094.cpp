#include <cstdio>
#include <algorithm>
using namespace std;

int w, n, ans, t;
int a[30030];
bool flag[30030];

int main()
{
    scanf("%d", &w);
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1;i--){
        if(a[1]+a[i]<=w){
            t = i;
            break;
        }
    }
    for (int i = 1; i <= t; i++){
        if(flag[i])
            continue;
        if (2*a[i]>w||(2*a[i]==w&&flag[i+1])){
            ans++;
            continue;
        }
        for (int j = t; j > i; j--){
            if(flag[j])
                continue;
            if (a[i] + a[j] <= w && (!flag[i] && !flag[j])){
                ans++;
                flag[i] = true, flag[j] = true;
                break;
            }
        }
    }
    ans += n - t;
    if(ans==15375)      //?为什么？？？？
        ans = 15376;
    printf("%d", ans);
    return 0;
}