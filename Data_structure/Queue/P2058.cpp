#include <cstdio>

int n, t, k, ans;
int i, j = 1;
int p[100005], x[1000005], nation[1000005];

int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &t, &k);
        while(k--){
            scanf("%d", &x[++i]);
            p[i] = t;
            if(!nation[x[i]])
                ans++;
            nation[x[i]]++;
        }
        while(t-p[j]>=86400){
            if(!--nation[x[j]])
                ans--;
            j++;
        }
        printf("%d\n", ans);
    }
    return 0;
}