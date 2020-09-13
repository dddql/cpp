#include <cstdio>

int n;
bool is_dollar=true;
double ans=100.00;
int a[105];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++){
        if(is_dollar){
            if(a[i]>a[i+1]&&i!=n){
                ans *= 1.0 * a[i] / 100;
                is_dollar = false;
            }
        }
        else{   //!这里一定要加等号！汇率可能与前一天一样
            if((a[i]<=a[i-1]&&a[i]<a[i+1]&&i!=n)||i==n){
                ans = ans * 100 / a[i] * 1.0;
                is_dollar = true;
            }
        }
    }
    printf("%.2lf", ans);
    return 0;
}