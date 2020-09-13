#include <cstdio>

int n, ans, l;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        int p;
        scanf("%d", &p);
        if(p>l){
            ans += p - l;
        }
        l = p;
    }
    printf("%d", ans);
    return 0;
}