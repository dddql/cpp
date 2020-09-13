#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[10];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        a[i] = i;
    do{
        for (int i = 1; i <= n;i++)
            printf("%5d", a[i]);
        printf("\n");
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}