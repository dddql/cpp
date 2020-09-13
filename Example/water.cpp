#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long sum;
struct p{
    int time;
    int index;
}a[1001];

bool cmp(p a,p b){
    if(a.time<b.time)
        return true;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i].time);
        a[i].index = i;
    }
    sort(a + 1, a + n + 1,cmp);
    for (int i = 1; i <= n;i++)
        sum += (n - i) * a[i].time;
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i].index);
    printf("\n%.2f", 1.0 * sum / n);
    return 0;
}