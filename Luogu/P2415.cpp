#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1e3;

long long t, n;
long long tot, ans;

int main(){
    while(scanf("%lld",&t)!=EOF){
        n++;
        tot += t;
    }
    ans = tot * pow(2, n - 1);
    printf("%lld", ans);
    return 0;
}