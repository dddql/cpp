#include <cstdio>
#include <cmath>
using namespace std;
int n, x, y;
int main()
{
    scanf("%d", &n);
    x = ceil((sqrt(8 * n + 1) - 1) / 2);
    y = n - (x * (x - 1)) / 2;
    printf("%d/%d", x & 1 ? x + 1 - y : y, x & 1 ? y : x + 1 - y);
    return 0;
}