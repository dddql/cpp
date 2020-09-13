#include <cstdio>
using namespace std;

int N, M;
int a[10000];

void bubble_sort(int data[], int length)
{
    bool if_swap;
    for (int i = 0; i < length - 1; i++)
    {
        if_swap = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
            if_swap = true;
        }
        if (if_swap == false)
            break;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    return 0;
}