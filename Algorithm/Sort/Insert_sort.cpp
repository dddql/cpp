#include <bits/stdc++.h>
using namespace std;

int len;

//TODO 插入排序模板
void Insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 2; i <= len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 1) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    cin >> len;
    int a[len];
    for (int i = 1; i <= len; i++)
        scanf("%d", &a[i]);
    Insertion_sort(a, len);
    for (int i = 1; i <= len; i++)
        printf("%d ", a[i]);
    return 0;
}