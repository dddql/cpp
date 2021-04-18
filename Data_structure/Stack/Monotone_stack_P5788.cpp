#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 3e6 + 10;

stack<int> s;

int n, a[maxn], ans[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    s.push(n), ans[n] = 0;
    for (int i = n - 1; i >= 1;i--){
        while(!s.empty()&&a[i]>=a[s.top()])
            s.pop();
        ans[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    for (int i = 1; i <= n;i++)
        printf("%d ", ans[i]);
    return 0;
}