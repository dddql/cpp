#include <cstdio>
#include <cstdlib>

using namespace std;

//TODO 快速排序模板
int a[1001];
int t[1001];
int n;

//*生成一个[l, r]以内的随机数
int getRand(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

//* 把[l,r]排序
void Quick_sort(int l, int r)
{
    if (l >= r) // 空区间或只有一个元素的区间
        return;

    int flag = a[getRand(l, r)];
    int p = l, q = r;

    //*把[l,r]排序
    for (int i = l; i <= r; i++)
    {
        if (a[i] < flag)
            t[p++] = a[i];
        if (a[i] > flag)
            t[q--] = a[i];
    }

    //*现在t[l, p-1]全是比flag小的，t[q+1, r]全是比flag大的
    for (int i = l; i <= p - 1; i++)
        a[i] = t[i];
    for (int i = r; i >= q + 1; i--)
        a[i] = t[i];
    for (int i = p; i <= q; i++)
        a[i] = flag;

    Quick_sort(l, p - 1);
    Quick_sort(q + 1, r);
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    Quick_sort(1, n);

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}