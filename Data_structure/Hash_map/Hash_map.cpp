//*哈希表模板
#include <cstdio>
#include <vector>
#define mod 114514
using namespace std;

vector<int> linker[mod+2];
int n, x, ans = 0;

inline void insert(int x){
    for (int i = 0; i < linker[x%mod].size();i++)
        if(linker[x%mod][i]==x)
            return;
    linker[x % mod].push_back(x);
    ans++;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &x);
        insert(x);
    }
    printf("%d", ans);
    return 0;
}