#include <cstdio>
using namespace std;

const int maxn = 200005;

struct stack{
    int a[maxn], t = 0;

    void push(int x){
        a[++t] = x;
    }

    void pop(){
        t--;
    }

    int top(){
        return a[t];
    }

    int size(){
        return t;
    }

    bool empty(){
        return t == 0;
    }
};

int n;
stack s, m;

int main(){
    scanf("%d", &n);
    while(n--){
        int opt;
        scanf("%d", &opt);
        if(opt==0){
            int x;
            scanf("%d", &x);
            if(x>=m.top())
                m.push(x);
            s.push(x);
        }
        else if(opt==1&&!s.empty()){
            if(s.top()==m.top())
                m.pop();
            s.pop();
        }
        else if(opt==2)
            printf("%d\n", m.top());
    }
    return 0;
}