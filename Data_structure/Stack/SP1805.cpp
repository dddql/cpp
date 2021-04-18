#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct rec{
    int h, w;
};

const int maxn = 1e5 + 5;
int n;
long long h[maxn], ans;

void calc(){
    ans = 0;
    stack<rec> s;
    s.push((rec){0, 0});
    h[n + 1] = 0;
    for (int i = 1; i <= n + 1;i++){
        if(h[i]>s.top().h)
            s.push((rec){h[i], 1});
        else{
            int wid = 0;
            while(s.top().h>h[i]){
                wid += s.top().w;
                ans = max(ans, s.top().h * wid * 1ll);
                s.pop();
            }
            s.push((rec){h[i], wid + 1});
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    while(scanf("%d",&n)){
        if(n==0)
            break;
        memset(h, 0, sizeof(h));
        for (int i = 1; i <= n;i++)
            scanf("%lld", &h[i]);
        calc();
    }
    return 0;
}