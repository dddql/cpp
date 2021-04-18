#include <cstdio>
#include <deque>
using namespace std;

const int maxn = 1e6 + 10;

int n, k;

struct node{
    int num;
    int val;
};

deque<node> q;
node a[maxn];

void Min(){
    for (int i = 1; i <= n;i++){
        while(!q.empty()&&a[i].val<=q.back().val)
            q.pop_back();
        q.push_back(a[i]);
        while(q.front().num<=i-k)
            q.pop_front();
        if(i>=k)
            printf("%d ", q.front().val);
    }
    q.clear();
}

void Max(){
    for (int i = 1; i <= n;i++){
        while(!q.empty()&&a[i].val>=q.back().val)
            q.pop_back();
        q.push_back(a[i]);
        while(q.front().num<=i-k)
            q.pop_front();
        if(i>=k)
            printf("%d ", q.front().val);
    }
    q.clear();
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i].val), a[i].num = i;
    Min();
    printf("\n");
    Max();
    return 0;
}