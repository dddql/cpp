//*循环队列的简单实现
#include <cstdio>
#include <queue>
using namespace std;

int n,m;
queue<int> q;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        q.push(i);
    while(q.size()){
        for (int i = 1; i < m;i++){
            q.push(q.front());  //*连接首尾，形成循环
            q.pop();
        }
        printf("%d ", q.front());
        q.pop();
    }
    return 0;
}