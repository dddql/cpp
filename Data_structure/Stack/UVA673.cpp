#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<char> s;
int n;

char trans(char c){
    if(c==')')
        return '(';
    if(c==']')
        return '[';
    return '\0';
}

int main()
{
    scanf("%d", &n);
    while(n--){
        string c;
        cin>>c;
        while(!s.empty())
            s.pop();
        for (int i = 0; i < c.length();i++){
            if(s.empty()){
                s.push(c[i]);
                continue;
            }
            if(trans(c[i])==s.top())
                s.pop();
            else
                s.push(c[i]);
        }
        printf(s.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}