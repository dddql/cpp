#include <cstdio>
using namespace std;

int n, k;
int cnt_A, cnt_B;
int sum_A, sum_B;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++) {
        if (i%k==0) {
            sum_A+=i;
            cnt_A++;
            continue;
        }
        sum_B+=i;
        cnt_B++;
    }
    printf("%.1f %.1f", sum_A*1.0/cnt_A, sum_B*1.0/cnt_B);
    return 0;
}