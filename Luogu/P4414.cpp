#include <cstdio>
#include <algorithm>
using namespace std;

int a[3];
char c[3];

int main()
{
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    sort(a, a + 3);
    scanf("%s", c);
    for (int i = 0; i < 3; i++)
        printf("%d ", a[c[i] - 'A']);
    return 0;
}