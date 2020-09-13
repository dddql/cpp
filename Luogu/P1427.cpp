#include <cstdio>
#include <stack>
using namespace std;

stack <long long> a;
long long k;

int main()
{
    while (scanf("%lld", &k)) {
        if (k==0) break;
        a.push(k);
    }
    while (!a.empty()){ 
        printf("%lld ", a.top());
        a.pop();
    }
    return 0;
}