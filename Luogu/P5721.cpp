#include <cstdio>

int n;
int x=1;

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){ 
        for (int j=0;j<=n-i;j++)
            printf("%02d", x++);
        printf("\n");
    }
    return 0;
}