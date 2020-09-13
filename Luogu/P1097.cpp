#include <cstdio>
#include <cstdlib>

int n,cnt=1;
int a[200001];
int t[200001];

int getrand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void Quick_sort(int l, int r) {
    if(l>=r)
        return;
    int flag = a[getrand(l, r)];
    int start = l, end = r;

    for (int i = l; i <= r;i++)
    {
        if(a[i]<flag)
            t[start++] = a[i];
        if(a[i]>flag)
            t[end--] = a[i];
    }

    for (int i = l; i <= start-1;i++)
        a[i] = t[i];
    for (int i = end+1; i <= r;i++)
        a[i] = t[i];
    for (int i = start; i <= end;i++)
        a[i] = flag;

    Quick_sort(l, start - 1);
    Quick_sort(end + 1, r);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    Quick_sort(1, n);
    for (int i = 1; i <= n;i++)
    {
        if(a[i+1]==a[i])
            cnt++;
        else
        {
            printf("%d %d\n", a[i], cnt);
            cnt = 1;
        }
    }
    return 0;
}