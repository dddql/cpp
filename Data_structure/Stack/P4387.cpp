#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1e5;

stack <int> s;

int a[maxn], b[maxn];
int p, n, cnt;

int main(){
    scanf("%d", &p);
    while(p--){
        cnt = 1;    //!记得刷新
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n;i++)
            scanf("%d", &b[i]);

        for (int i = 1; i <= n;i++){
            s.push(a[i]);
            while((s.top())==b[cnt]){
                s.pop(), cnt++;
                if(s.empty())
                    break;
            }
        }
        printf(s.empty() ? "Yes\n" : "No\n");

        while(!s.empty())
            s.pop();
    }
    return 0;
}