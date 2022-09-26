#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

const int maxn = 1e5+10;
const int log = 21;

int n,m;
int f[maxn][log + 1], log2[maxn];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = (x << 3) + (x << 1) + (ch - 48);
        ch = getchar();
    }
    return x * f;
}

void init(){
    log2[0] = -1;
    for (int i = 1; i <= n;i++)
        log2[i] = log2[i >> 1] + 1;
    for (int j = 1; j <= log;j++)
        for (int i = 1; i + (1 << j) - 1 <= n;i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j-1))][j - 1]);
}

int query(int l,int r){
    int k = log2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n;i++)
        f[i][0] = read();
    init();
    for (int i = 1; i <= m;i++){
        int l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}