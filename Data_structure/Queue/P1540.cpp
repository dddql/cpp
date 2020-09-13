#include <cstdio>
#include <queue>
using namespace std;

int M, N, tmp, ans;
bool find[1050];
queue<int> mem;

int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N;i++){
        scanf("%d", &tmp);
        if(find[tmp])
            continue;
        else{
            if(mem.size()>=M){
                find[mem.front()] = false;
                mem.pop();
            }
            mem.push(tmp);
            find[tmp] = true;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}