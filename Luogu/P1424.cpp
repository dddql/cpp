#include <cstdio>
using namespace std;
int main()
{
    int n, k, dis = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        if (n != 6 && n != 7)
            dis += 250;
        if (n == 7)
            n = 1;
        else
            n++;
    }
    printf("%d", dis);
    return 0;
}