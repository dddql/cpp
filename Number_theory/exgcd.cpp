#include <cstdio>

long long x,y;

void exgcd(long long a,long long b){
    if(b==0){
        x = 1;
        y = 0;
        return;
    }

    //*先求下一个方程的解
    exgcd(b, a % b);

    //*更新这一层的解
    long long tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    exgcd(a, b);

    //*化为最小整数解
    x = (x % b + b) % b;

    printf("%lld\n", x);
    return 0;
}