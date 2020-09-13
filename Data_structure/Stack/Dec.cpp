//*Dec数制转换

//*数组模拟栈
/*#include <cstdio>

int a[105];
int n, d, i = 0;

int main()
{
    scanf("%d%d", &n, &d);
    while(n){
        a[++i] = n % d;
        n /= d;
    }
    while(i)
        printf("%d", a[i--]);
    return 0;
}*/

//*STL栈
#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
int n, d;

int main()
{
    scanf("%d%d", &n, &d);
    while(n){
        s.push(n % d);
        n /= d;
    }
    while(!s.empty()){
        printf("%d", s.top());
        s.pop();
    }
    return 0;
}