#include <cstdio>

int n;

int sum(int n){
    if (n==1) return 1;
    return sum(n-1)+n;
}

int main()
{
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}