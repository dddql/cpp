#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 5;

struct monster{
    int num;
    int a, b;
};

int n, k;
vector<monster> a;

bool cmp(monster a,monster b){
    return a.a > b.a;
}

void init(){
    scanf("%d%d", &n, &k);
    a.resize(n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d", &a[i].a, &a[i].b);
        a[i].num = i;
    }
}

int main()
{
    init();

    sort(a.begin(), a.end(), cmp);

    for (int i = 1; i <= a.size();i++)
        for (int j = 1; j <= a.size(); j++)
        {
            if (a[j].a <= k && k - a[j].b >= a[j + 1].a)
            {
                k -= a[j].b;
                a.erase(a.begin() + j);
                printf("%d ", a[j].num);
            }
        }
    
    if(!a.empty())
        printf("N0");
    return 0;
}