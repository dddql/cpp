//todo 放进 1，放进 2，清洗， 放进 3，放进 4，清洗，清洗，放进 5，清洗，清洗
#include <cstdio>

int count;

struct Stack{

    struct node {
        node* below;
        int key;                    //*这个元素的值
    }*nowTop = NULL;

    void push(int x) {              //*向栈顶压入一个数
        node* todo = new node();
        todo->below = nowTop;
        todo->key = x;
        nowTop = todo;
        count++;
    }

    void pop() {                    //*弹出栈顶
        node *old = nowTop;
        nowTop = old->below;
        delete old;
        count--;
    }

    int top() {                     //*返回栈顶的值
        return nowTop->key;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;    //*nowTop ==NULL
    }
};

Stack s;

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
