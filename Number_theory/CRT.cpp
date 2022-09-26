#include <cstdio>

typedef long long ll;

const int maxn = 11;

ll n, ans, x, y;
ll N = 1;
ll a[maxn], b[maxn], m[maxn];
//*a为模数，b为余数，c为逆元，m为其他模数之积

void exgcd(ll a,ll b){
    if(b==0){
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    ll tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n;i++){
        scanf("%lld%lld", &a[i], &b[i]);
        N *= a[i];
    }
    for (int i = 1; i <= n;i++){
        m[i] = N / a[i];
        x = 0, y = 0;
        exgcd(m[i], a[i]);
        ans += b[i] * m[i] * x;
        ans = (ans % N + N) % N;
    }
    printf("%lld", ans % N);
    return 0;
}

void diandao(){
    //颠倒的过程；
}
int main(){
    scanf("....");
    diandao();
    printf("....");
}
