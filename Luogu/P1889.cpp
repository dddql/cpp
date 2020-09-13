#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int x[10001], y[10001];
int mid_y,mid_x,sum_y=0,sum_x=0,sum=0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &x[i], &y[i]);

    sort(y + 1, y + n + 1);
    sort(x + 1, x + n + 1);

    for (int i = 1; i <= n;i++)
        x[i] -= i;
    sort(x + 1, x + n + 1);

    if(n%2==1){
        mid_y = y[(n/2)+1];
        mid_x = x[(n/2)+1];
    }
    else{
        mid_y = (y[n / 2] + y[n / 2 + 1]) / 2;
        mid_x = (x[n / 2] + y[n / 2 + 1]) / 2;
    }

    for (int i = 1; i <= n;i++){
        sum_y += abs(y[i] - mid_y);
        sum_x += abs(x[i] - mid_x);
    }
    sum = sum_x + sum_y;
    printf("%d", sum);
    return 0;
}