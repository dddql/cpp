#include <cstdio>
#include <cmath>
#include <algorithm>

int n, k;
int ans;
int a[21];

bool is_prime(int n){
	if(n<2) return false;
	if(n==2||n==3) return true;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
            return false;
    return true;
}

int cnt_1(int n) {      //*计算二进制数字中1的个数
    int cnt=0;
    while(n){
        if(n&1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    int U = (1 << n) - 1;
    for (int S = 1; S <= U;S++){
        if(__builtin_popcount(S)==k){
            int sum = 0;
            for (int i = 1; i <= n;i++)
                if(S & (1 << (i - 1)))
                    sum += a[i];
            if(is_prime(sum))
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}