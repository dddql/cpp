#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    for(int x=n-1092;x>=0;x--)
    {
        if (364*x>n) continue;
        for(int k=1;k<=n/1092;k++){ 
            if (364*x+1092*k==n&&x<=100) {
                printf("%d\n%d", x, k);
                return 0;
            }
        }
    }
    return 0;
}