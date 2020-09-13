#include <cstdio>
#include <cmath>        //*判断质数时需使用sqrt()
#include <algorithm>    //*使用__builtin_popcount()需包含该头文件

int n, k;
int ans;
int a[21];

bool is_prime(int n){   //*判断是否为质数
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
    int U = (1 << n) - 1;               //*U为全集，易知 U=2^n-1
    for (int S = 1; S <= U;S++){        //*枚举每一个子集
        if(cnt_1(S)==k){                //*判断子集中是否有k个元素（可以用__builtin_popcount()函数代替）
            int sum = 0;
            for (int i = 1; i <= n;i++)
                if(S & (1 << (i - 1)))      //*判断第i个元素是否在S中
                    sum += a[i];
            if(is_prime(sum))
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
//__builtin_popcount