#include <cstdio>
#include <cctype>
#include <algorithm>

const int maxn = 5e4 + 10;
const int max_log = 16;

int n, q;

int dp_max[maxn][max_log + 2];
int dp_min[maxn][max_log + 2];
int log2[maxn];

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
    for (int j = 1; j <= max_log;j++)
        for (int i = 1; i + (1 << j) - 1 <= n;i++){
            dp_max[i][j] = std::max(dp_max[i][j - 1], dp_max[i + (1 << (j-1))][j - 1]);
            dp_min[i][j] = std::min(dp_min[i][j - 1], dp_min[i + (1 << (j-1))][j - 1]);
        }
}

int main(){
    n = read(), q = read();
    for (int i = 1; i <= n;i++)
        dp_max[i][0] = dp_min[i][0] = read();
    init();
    for (int i = 1; i <= q;i++){
        int a = read();
        int b = read();
        int log = log2[b - a + 1];
        int max = std::max(dp_max[a][log], dp_max[b - (1 << log) + 1][log]);
        int min = std::min(dp_min[a][log], dp_min[b - (1 << log) + 1][log]);
        printf("%d\n", max - min);
    }
    return 0;
}