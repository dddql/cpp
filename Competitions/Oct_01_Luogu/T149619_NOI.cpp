#include <cstdio>
typedef long long ll;

ll a, b, c, d, e, f, g, h, i;
ll ans;

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h, &i);
    if(h)
        h = 5;
    ans = a + b + c + d + e + f + g + h;
    if(ans>=i)
        printf("AKIOI");
    else
        printf("AFO");
    return 0;
}