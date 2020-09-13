#include <cstdio>
#include <stack>
using namespace std;

stack <int> a;
int n;

int main()
{
    scanf("%d", &n);
    a.push(n);
    while (n!=1) {
        if (n%2==0)
            n/=2;
        else n=n*3+1;
        a.push(n);
    }
    while (!a.empty()) {
        printf("%d ", a.top());
        a.pop();
    }
    return 0;
}