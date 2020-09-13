//*STL栈
/*
#include <cstdio>
#include <stack>
using namespace std;

stack<char> s;
char c='\0';

int main()
{
    while(c!='@'){
        scanf("%c", &c);
        if(c=='(')
            s.push(c);
        if(c==')'){
            if(!s.empty()&&s.top()=='(')
                s.pop();
            else{
                printf("NO");
                return 0;
            }
        }
    }
    printf(s.empty() ? "YES" : "NO");
    return 0;
}*/

//*数组模拟
#include <cstdio>

int tot = 0;
struct stack{
    char a[256];
    void push(char c){
        a[++tot] = c;
    }
    void pop(){
        tot--;
    }
    char top(){
        return a[tot];
    }
    int size(){
        return tot;
    }
    bool empty(){
        return tot == 0;
    }
};

stack s;
char c = '\0';

int main()
{
    while(c!='@'){
        scanf("%c", &c);
        if(c=='(')
            s.push(c);
        if(c==')'){
            if(!s.empty() && s.top()=='(')
                s.pop();
            else{
                printf("NO");
                return 0;
            }
        }
    }
    printf(s.empty() ? "YES" : "NO");
    return 0;
}

