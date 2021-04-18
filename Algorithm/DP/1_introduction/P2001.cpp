#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 2e6+5;
const long long max_m = 2e8+5;
const long long INF = 0xfffffff;

int a[max_n], f[max_m];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    if(a[1]!=1){
        printf("No answer!!!");
        return 0;
    }
    
    for (int i = 1; i <= m;i++){
        int last = INF;
        for (int j = 1; j <= n;j++)
            if(i-a[j]>=0)
                last = min(last, f[i - a[j]]);
        f[i] = last + 1;
        if(f[i]>n||last==INF){
            printf("No answer!!!");
            return 0;
        }
    }
    printf("%d", f[m]);
    return 0;
}