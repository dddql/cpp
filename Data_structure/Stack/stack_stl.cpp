//todo 放进 1，放进 2，清洗， 放进 3，放进 4，清洗，清洗，放进 5，清洗，清洗
#include <cstdio>
#include <stack>
using namespace std;        //!一定要加这一句

stack <int> s;

int main(){
    s.push(1);
    s.push(2);
    printf("%d\n",s.top());

    s.pop();
    printf("%d\n",s.top());

    s.push(3);
    s.push(4);
    printf("%d\n",s.top());

    s.pop();
    printf("%d\n",s.top());

    s.pop();

    s.push(5);
    printf("%d\n",s.top());

    s.pop();
    printf("%d\n",s.top());

    s.pop();

    return 0;
}
