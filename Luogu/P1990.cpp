#include <cstdio>

const int MAXN = 10;

int n;
int a[MAXN], sum[MAXN];

int count(int n)
{
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;

    /*
    sum[0] = 1;
    sum[1] = 2;
    sum[2] = 4;
    */
   
    if (n == 0 || n == 1 || n == 2)
        return n;

    //*a[i]-a[i-1]化简得递推式
    for (int i = 3; i <= n; i++)
        a[i] = 2 * a[i - 1] % 10000 + a[i - 3] % 10000;

    /*前缀和做法
    for (int i = 3; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i - 2] + 2 * (sum[i - 3])) % 10000;
        sum[i] = (sum[i - 1] + a[i]) % 10000;
    }
    */
    return a[n] % 10000;
}
int main()
{
    scanf("%d", &n);
    printf("%d", count(n));
    return 0;
}