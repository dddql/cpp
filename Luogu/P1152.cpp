#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
bool flag = true;
int a[1001];
int c[100000001];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    a[0] = n;
    for (int i = 0; i < n;i++)
        c[abs(a[i + 1] - a[i])]++;
    for (int i = 1; i < n;i++)
        if(c[i]==0)
            flag = false;
    if(flag)
        printf("Jolly");
    else
        printf("Not jolly");
    return 0;
}