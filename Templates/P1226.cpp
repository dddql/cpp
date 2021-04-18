//*快速幂
#include <cstdio>

long long b, p, k;
long long result = 1;

void mod(long long b, long long p, long long k) {
    while(p){
        if(p & 1)
            result =(result* b)%k;
        b = (b * b)%k;
        p >>= 1;
    }
}

int main()
{
    scanf("%lld%lld%lld", &b, &p, &k);
    mod(b, p, k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, result % k);
    return 0;
}

