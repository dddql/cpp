#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int a[10000];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N;i++)
        scanf("%d", &a[i]);
    for (; M--;)
        next_permutation(a + 1, a + N + 1);
    for (int i = 1; i <= N;i++)
        printf("%d ", a[i]);
    return 0;
}