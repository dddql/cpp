#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e1;
const int INF = 0x3f3f3f3f;

struct stack{//栈
    int a[maxn], tot = 0;
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
        return tot == 0;
    }
    void print(){
        for (int i = 1; i <= tot;i++)
            printf("%d ", a[i]);
        printf("\n");
    }
} s;

struct queue{//普通队列
    int a[maxn];
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
    int end(){
        return a[tail];
    }
    int size(){
        return tail - head + 1;
    }
    bool emrty(){
        return tail < head;
    }
    void print(){
        for (int i = head; i <= tail;i++)
            printf("%d ", a[i]);
        printf("\n");
    }
} q;

struct BST{
    struct Node{
        int ls, rs;
        int size, val, num;

        Node(int l = 0,int r = 0,int s = 0,int v = 0){
            ls = l, rs = r, size = s, val = v;
            num = 1;
        }
    } t[maxn];

    void init(){
        t[root = ++cnt] = Node(0, 0, 1, INF);
    }

    void update(int root){
        t[root].size = t[t[root].ls].size + t[t[root].rs].size + t[root].num;
    }

    void insert(int x,int root){
        if(x<t[root].val)
            if(!t[root].ls)
                t[t[root].ls = ++cnt] = Node(0, 0, 1, x);
            else
                insert(x, t[root].ls);
        else if(x==t[root].val)
            t[root].num++;
        else
            if(!t[root].rs)
                t[t[root].rs = ++cnt] = Node(0, 0, 1, x);
            else
                insert(x, t[root].rs);
    }

    int rank(int x,int root){
        if(root){
            if(x<t[root].val)
                return rank(x, t[root].ls);
            else if(x>t[root].val)
                return rank(x, t[root].rs) + t[t[root].ls].size + t[root].num;
            else
                if()
        }
    }
}

int n,m;

int main(){
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    printf("%d\n", q.size());
    q.push(4);
    q.push(5);
    q.print();
    return 0;
}