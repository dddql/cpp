#include <cstdio>

struct queue{
    int a[10005];
    int head = 1, tail = 0;

    void push(int x){
        a[++tail] = x;
    }

    void pop(){
        head++;
    }

    int size(){
        return tail - head + 1;
    }

    int front(){
        return a[head];
    }
};

queue q;
int base, n;

int main()
{
    //while(){
    int t2, t3, two = 1, three = 1;
    scanf("%d%d\n", &base, &n);
    q.push(base);
    while (q.tail < n)
    {
        t2 = 2 * q.a[two] + 1;
        t3 = 3 * q.a[three] + 1;
        int t= min(t2,t3);
        if(t>q.a[q.tail])
            q.push(t);
        if(t2<t3)
            two++;
        else
            three++;
        }
        printf("%d", q.a[n]);
    //}
    return 0;
}