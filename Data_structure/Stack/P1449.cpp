#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
int n, x, y;
char op;

int main()
{
    do{
        scanf("%c", &op);
        if(op>='0'&&op<='9')
            n = n * 10 + (op - '0');
        else if(op=='.'){
            s.push(n);
            n = 0;
        }
        else if(op!='@'){
            x = s.top(); s.pop();
            y = s.top(); s.pop();
            switch (op){
                case '+': s.push(x + y); break;
                case '-': s.push(y - x); break;
                case '*': s.push(x * y); break;
                case '/': s.push(y / x); break;
            }
        }
    } while (op != '@');
    printf("%d", s.top());
    return 0;
}