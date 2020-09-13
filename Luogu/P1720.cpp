#include <cstdio>

int n;
unsigned long long ans[49];

double fib(int x){
    ans[1]=ans[2]=1;
    if (x==1||x==2) return ans[x]*1.0;
    for (int i=3;i<=x;i++)
        ans[i]=ans[i-1]+ans[i-2];
    return ans[x]*1.0;
}
int main()
{
    scanf("%d", &n);
    printf("%.2lf", fib(n));
    return 0;
}