#include <cstdio>

int n;
int num=1;

int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++){ 
        for (int j=1;j<=n;j++)
            printf("%02d", num++);
        printf("\n");
    }

    printf("\n");
    num=1;

    for(int i=1;i<=n;i++){ 
        for (int j=2*n-i;j>=1;j--){ 
            if (j>i) printf(" ");
            else printf("%02d", num++);
        }
        printf("\n");
    }
    return 0;
}