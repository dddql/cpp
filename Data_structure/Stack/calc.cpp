#include <cstdio>
#include <cctype>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

const int MOD = 10000;
string p;
int i = 0;

stack<int> num;
stack<char> op;

int prior[256];

void init_prior(){
    prior['('] = 4;
    prior['^'] = 3;
    prior['*'] = prior['/'] = 2;
    prior['+'] = prior['-'] = 1;
    prior[')'] = 0;
}

bool cmp_op(char x,char y){
    return prior[x] > prior[y];
}

int calc(int a,char op,int b){
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
    }
}

int read(){
    int s = 0;
    while(isdigit(p[i]))
        s = s * 10 + (p[i++] - '0');
    i--;
    return s;
}

int main()
{
    init_prior();

    scanf("%s", p.c_str());

    while(p[i]!='\0'){
        if(isdigit(p[i]))
            num.push(read());
        else if(p[i]=='-'&&(!isdigit(p[i-1])||i==0)){
            i++;
            num.push(-1 * read());
        }
        else{
            while(!op.empty()&&cmp_op(op.top(),p[i])){
                char o = op.top();op.pop();
                int y = num.top();num.pop();
                int x = num.top();num.pop();
                int result = calc(x, o, y)%MOD;
                num.push(result%MOD);
            }
            op.push(p[i]);
        }
        i++;
    }

    while(!op.empty()){
        char o = op.top();op.pop();
        int y = num.top();num.pop();
        int x = num.top();num.pop();
        int result = calc(x, o, y)%MOD;
        num.push(result%MOD);
    }

    printf("%d", num.top()%MOD);
    return 0;
}