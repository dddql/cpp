#include <cstdio>
struct queue{
    int a[1005];
    int head = 1, tail = 0;

    void push(int x){
        a[++tail] = x;
    }

    void pop(){
        head++;
    }

    int front(){
        return a[head];
    }

    int size(){
        return tail - head + 1;
    }

    bool empty(){
        return head>tail;
    }
};
queue x, y;

int m, n, k;
void q_init(){
    for (int i = 1; i <= m;i++)
        x.push(i);
    for (int i = 1; i <= n;i++)
        y.push(i);
}

int main()
{
    scanf("%d%d\n%d", &m, &n, &k);
    q_init();
    for (int i = 1; i <= k;i++){
        printf("%d %d\n", x.front(), y.front());
        x.push(x.front()), y.push(y.front());
        x.pop(), y.pop();
    }
    return 0;
}