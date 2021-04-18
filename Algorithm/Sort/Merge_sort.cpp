#include <cstdio>
using namespace std;

int n;

//TODO 归并排序模板
void mergesort(int l, int r, int ans[], int temp[])
{
    if (l == r)
        return;

    //排序
    int mid = (l + r) / 2;

    mergesort(l, mid, ans, temp);     // 排序 a[l,mid]
    mergesort(mid + 1, r, ans, temp); // 排序 a[mid+1,n]

    //合并两有序数组 时间复杂度为O(n)
    int p = l, q = mid + 1, i = l; // 合并到 t[l,r]

    while (p <= mid && q <= r)
    {
        if (ans[p] < ans[q])
            temp[i++] = ans[p++]; // i++,p++表示先i=p，再各自++
        else
            temp[i++] = ans[q++];
    }

    while (p <= mid) // 左边队伍没取完
        temp[i++] = ans[p++];
    while (q <= r) // 右边队伍没取完
        temp[i++] = ans[q++];

    for (int i = l; i <= r; i++) // 将暂存的答案拷贝回原数组
        ans[i] = temp[i];
}
int main()
{
    scanf("%d", &n);
    int a[n + 1], t[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    mergesort(1, n, a, t);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}