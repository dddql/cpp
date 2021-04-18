#include <cstdio>
#include <algorithm>
#include <string.h>
#define maxn 10000
using namespace std;

struct Bigint{
    int len,a[maxn];

    Bigint(int x=0){
        memset(a, 0, sizeof(a));
        for (len = 1; x;len++){
            a[len] = x % 10;
            x /= 10;
        }
        len--;
    }

    int &operator[](int i){
        return a[i];
    }

    void flatten(int L){
        len = L;
        for (int i = 1; i <= len; i++){
            if(a[i]>=10){
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
            }
        }
        for (; !a[len];)
            len--;
    }

    void print(){
        for (int i = max(len, 1); i >= 1;i--)
            printf("%d", a[i]);
    }
};

Bigint operator+(Bigint a,Bigint b){
    Bigint c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len;i++)
        c[i] += a[i] + b[i];
    c.flatten(len + 1);
    return c;
}

Bigint operator*(Bigint a,int b){
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len;i++)
        c[i] = a[i] * b;
    c.flatten(len + 11);
    return c;
}

int main()
{
    Bigint ans(0), fac(1);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        fac = fac * i;
        ans = ans + fac;
    }
    ans.print();
    return 0;
}