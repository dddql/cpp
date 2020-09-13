//todo 放进 1，放进 2，清洗， 放进 3，放进 4，清洗，清洗，放进 5，清洗，清洗
#include <cstdio>
#include <queue>
using namespace std;

queue <int> q;

int main(){
    q.push(1);
    printf("%d\n",q.front());

    q.push(2);
    printf("%d\n",q.front());

    q.pop();
    printf("%d\n",q.front());

    q.push(3);
    printf("%d\n",q.front());

    q.pop();
    printf("%d\n",q.front());

    q.pop();

    //*q.size();
    //*q.empty();

    return 0;
}
