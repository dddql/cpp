#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5000000;
int n, k;
int a[maxn];

inline int read(){
    int f = 1, x = 0;
    char c = getchar();

    while(c<'0'||c>'9'){
        if(c=='-')
            f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x * f;
}

int main()
{
    n = read();
    k = read();
    for (int i = 1; i <= n;i++)
        a[i] = read();
    sort(a, a + n + 1);
    printf("%d", a[k+1]);
    //nth_element(a+1, a + k, a + n + 1);
    //printf("%d", a[k+1]);
    return 0;
}