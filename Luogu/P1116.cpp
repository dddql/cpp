#include <cstdio>
#include <iomanip>

using namespace std;

int a[10000];
int n;

int bubble_sort_cnt(int data[], int length)
{
    int cnt = 0;
    bool if_swap;
    for (int i = 0; i < length - 1; i++)
    {
        if_swap = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                cnt++;
            }
            if_swap = true;
        }
        if (!if_swap)
            break;
    }
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", bubble_sort_cnt(a, n));
    return 0;
}