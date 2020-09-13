#include <cstdio>
#include <algorithm>
using namespace std;

int s[1001], k;
int n, h;

struct stick{
    int len;
    int w;
} a[1001];

bool cmp(stick a,stick b){
    return a.len < b.len;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &a[i].len, &a[i].w);
    sort(a + 1, a + n + 1, cmp);
    
    return 0;
}