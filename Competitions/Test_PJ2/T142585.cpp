#include <cstdio>
#include <cmath>

#define M 1000000007

using namespace std;

int n, m;
int a[1000001];

int work(int n, int m) {

    if (n<m||m==1)
        return 1;
    if (n==m)
        return 2;
    if (n>m) {
        for (int i=1;i<m;i++)
            a[i]=1;
        a[m]=2;
        for (int i=m+1;i<=n;i++)
            a[i]=a[i-1]%M+a[i-m]%M;
        return a[n];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    printf("%d", work(n, m)%M);
    return 0;
}