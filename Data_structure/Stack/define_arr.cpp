#include <cstdio>

struct stack{
    int a[105],tot = 0;
    void push(int x){
        a[++tot] = x;
    }
    void pop(){
        tot--;
    }
    int top(){
        return a[tot];
    }
    int size(){
        return tot;
    }
    bool empty(){
        return tot > 0;
    }
};

stack s;

int main()
{
    
    return 0;
}