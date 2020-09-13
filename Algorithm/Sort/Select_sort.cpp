#include <bits/stdc++.h>
using namespace std;
//TODO 选择排序模板
void Select_sort(int data[], int length)
{
    int k;
    for (int i = 0; i < length; i++)
    {
        k = i;
        for (int j = i; j < length; j++)
        {
            if (data[j] < data[k])
                k = j;
        }
        if (k != i)
            swap(data[i], data[k]);
    }
}
int main()
{
    int len;
    cin >> len;
    int a[len];
    for (int i = 0; i < len; i++)
        cin >> a[i];
    Select_sort(a, len);
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    return 0;
}