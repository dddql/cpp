#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 105;

stack<int> s;
string c;
char b[maxn];

char trans(char c){
    if(c==')')
        return '(';
    if(c==']')
        return '[';
    if(c=='(')
        return ')';
    else
        return ']';
}

int main()
{
    cin>>c;
    int len = c.size();
    for (int i = 0; i < len;i++){
        if(c[i]=='('||c[i]=='['){
            s.push(i);
            b[i] = trans(c[i]);
        }
        else{
            if(!s.empty()&&c[s.top()]==trans(c[i])){
                b[s.top()] = ' ';
                s.pop();
            }
            else
                b[i] = trans(c[i]);
        }
    }

    for (int i = 0; i < len;i++){
        if(b[i]=='('||b[i]=='[')
            cout << b[i];
        cout << c[i];
        if(b[i]==')'||b[i]==']')
            cout << b[i];
    }
    return 0;
}