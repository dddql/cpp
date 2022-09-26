#include <cstdio>
#include <cstring>

const int maxn = 1e8 + 10;

bool isPrime[maxn];
int prime[maxn], cnt = 0;

void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    GetPrime(n);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}