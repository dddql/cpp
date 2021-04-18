#include <cstdio>
#include <algorithm>
using namespace std;

int sum = 0;
int c[7] = {0, 1, 2, 3, 5, 10, 20}, a[6];
int f[1001];

int main(){
    f[0] = 1;
    for (int i = 1; i <= 6;i++){
        scanf("%d", &a[i]);
        sum += a[i] * c[i];
    }
    for (int i = 1; i <= 6;i++)
        for (int j = c[i]; j <= sum;j++)
            for (int k = 1; k <= a[i];k++)
                f[j] = f[j] + f[j - k * c[i]];
    int t = 0;
    for (int i = 1; i <= sum;i++)
        if(f[i]!=0)
            t++;
    printf("%d", t);
    return 0;
}