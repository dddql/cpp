#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1e8 - 3;

int n;
int a[maxn], b[maxn];
int c[maxn];

long long dis(){
    long long ans = 0;
    for (int i = 1; i <= n;i++)
        ans += (long long)((a[i] - b[i]) * (a[i] - b[i]));
    return ans;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);

    return 0;
}