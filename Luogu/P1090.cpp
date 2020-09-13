#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[10005],sum;

bool cmp(int a,int b){
    return a < b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 2; i <= n;i++){
        a[i] += a[i - 1];
        sum += a[i];
        for (int j = i; j < n;j++){
            if(a[j]>a[j+1])
                swap(a[j], a[j + 1]);
        }
    }
    printf("%d", sum);
    return 0;
}