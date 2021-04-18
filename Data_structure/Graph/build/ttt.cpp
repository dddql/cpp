#include <cstdio>
#include <queue>
using namespace std;

struct tt{
    int a, b;
};

queue<tt> q;


int main()
{
    q.push();
    printf("%d", q.front().a);
    return 0;
}