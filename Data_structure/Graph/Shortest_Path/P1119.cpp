#include <cstdio>
#include <algorithm>

const int maxn = 2e2 + 5;
const int INF = 1e9;

int n, m, cur;
int t[maxn], e[maxn][maxn];

int init(){
	char c = getchar();
	int x = 0, f = 1;
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-') f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 1) + (x << 3) + (c ^ 48);
	return x * f;
}
void print(int x){
	if (x < 0) x = -x, putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void build(){
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            e[i][j] = (i == j ? 0 : INF);
}

void update(int k){
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            //*注意双向的松弛
            e[i][j] = e[j][i] = std::min(e[i][j], e[i][k] + e[k][j]);
}

int main(){
    n = init(), m = init();
    build();
    for (int i = 0; i < n;i++)
        t[i] = init();
    for (int x = 0; x < m; x++){
        int i,j,w;
        i = init(), j = init(), w = init();
        e[i][j] = e[j][i] = w;
    }

    int Q = init();
    for (int q = 1; q <= Q;q++){
        int x, y, tt;
        x = init(), y = init(), tt = init();
        while(t[cur]<=tt&&cur<n){
            update(cur);
            cur++;
        }
        if((t[x]>tt)||(t[y]>tt)||(e[x][y]==INF))
            printf("-1\n");
        else
            printf("%d\n",e[x][y]);
    }
    return 0;
}