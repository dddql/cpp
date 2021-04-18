#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 0x7fffffff;

multiset<int> s;

int n, x, ans;

int main(){
    s.insert(INF), s.insert(-INF);

    scanf("%d", &n);
    scanf("%d", &x);
    s.insert(x), ans = x;

    while(--n){
        scanf("%d", &x);
        multiset<int>::iterator it = s.insert(x);
        multiset<int>::iterator l = --it;
        it++;
        multiset<int>::iterator r = ++it;
        it--;
        if(*l==-INF)
            ans += *r - x;
        if(*r==INF)
            ans += x - *l;
        if(*l!=-INF&&*r!=INF)
            ans += min(*r - x, x - *l);
    }
    printf("%d", ans);
    return 0;
}