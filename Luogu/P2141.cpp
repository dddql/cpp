#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 105;

int n, ans;
int a[maxn];

bool cmp(int a,int b){
    return a > b;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    sort(a+1, a + n + 1, cmp);
    for (int i = 1; i <= n - 2;i++){
        bool flag = false;
        for (int j = i + 1; j <= n - 1;j++){
            for (int k = j + 1; k <= n;k++){
                if(a[i]==a[j]+a[k]){
                    ans++;
                    flag = true;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
    }
    printf("%d", ans);
    return 0;
}