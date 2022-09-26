#include <cstdio>

const int maxn = 1e6 + 5;

long long N,M;
int a[maxn];

bool check(int x){
    long long sum = 0;
    for (int i = 1; i <= N; i++)
        if(a[i]>x)
            sum += a[i] - x;
    return sum >= M;
}

long long find(){
    long long l = 1, r = 1e9 + 1, mid = (l + r + 1) >> 1;
    while(l+1 < r){       //l,r不相邻
        if(check(mid))
            l = mid;
        else
            r = mid;
        mid = (l + r + 1) >> 1;
    }
    return l;           //返回左值
}
int main(){
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N;i++)
        scanf("%d", &a[i]);
    printf("%lld", find());
    return 0;
}