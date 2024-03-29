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
queue q;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        q.push(i);

    for (int i = n; i >= 1;i--){
        printf("%d %d ", q.size(), q.front());
        q.pop();
        if(q.empty())
            printf("Empty!\n");
        else
            printf("Has Elements!\n");
    }
    return 0;
}