//! 从2到sqrt(n)比从n到sqrt(n)枚举次数少
#include <cstdio>
#include <cmath>

int n;

int main()
{
    scanf("%d", &n);
    for(int i=2;i<=sqrt(n);i++)
        if (n%i==0) { 
            printf("%d", n/i);
            return 0;
        }
    return 0;
}