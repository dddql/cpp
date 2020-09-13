#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int t1, t2;
int sum,temp;
bool flag;
struct num{
    int d;
    int cnt;
} a[100001]; 

int cal(num a,num b){
    if(a.cnt<b.cnt)
        return a.cnt * (a.d + b.d);
    else
        return b.cnt * (a.d + b.d);
}

bool cmp(num a,num b){
    return a.d < b.d;
}

int main()
{
    scanf("%d%d", &n, &k);
    
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &a[i].d, &a[i].cnt);

    if(n==1){             //*特判n=1
        if(k==0)
            printf("%d", a[1].cnt * a[1].d);
        else
            printf("NO");
        return 0;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i < n;i++){            //*去重
        if(a[i].d==a[i+1].d){
            a[i].cnt += a[i+1].cnt;
            a[i+1].cnt = 0;
            a[i+1].d = 0;
        }
    }

    if(k==0){               //*特判k=0
        for (int i = 1; i <= n;i++){
            int tp = a[i].cnt * a[i].d;
            if (tp > sum)
                sum = tp;
        }
        printf("%d", sum);
        return 0;
    }

    sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if(a[i].d-a[j].d>k)
                break;
            if (a[i].d - a[j].d == k&&(a[i].cnt!=0&&a[j].cnt!=0))
            {
                flag = true;
                if(i==j)
                    temp = a[i].d * a[i].cnt;
                else
                    temp = cal(a[i], a[j]);
                if (temp > sum)
                    sum = temp;
            }
        }
    }
    if(flag)
        printf("%d", sum);
    else
        printf("NO");
    return 0;
}