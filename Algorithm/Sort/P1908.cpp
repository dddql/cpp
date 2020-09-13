#include <cstdio>
#define maxn 500050

long long n, ans;
int a[maxn];
int t[maxn];

void merge_sort(int a[],int l,int r){
    if(l==r)
        return;
    int mid = (l + r) >> 1;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    int p = l, q = mid + 1, i = l;
    
    while(p<=mid&&q<=r){
        if(a[p]<=a[q])
            t[i++] = a[p++];
        else{
            t[i++] = a[q++];
            ans += mid - p + 1;
        }
    }

    while (p <= mid)
        t[i++] = a[p++];
    while (q <= r)
        t[i++] = a[q++];
    for (int i = l; i <= r;i++)
        a[i] = t[i];
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    merge_sort(a, 1, n);
    printf("%lld", ans);
    return 0;
}