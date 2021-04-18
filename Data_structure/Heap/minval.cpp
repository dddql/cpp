#include <cstdio>
#include <algorithm>
using namespace std;

#define f(i,j) f[i].a*j*j+f[i].b*j+f[i].c

const int maxn = 1e4 + 5;

struct func{
    int a, b, c;
    int index, num;
} f[maxn];

struct heap{
    int heap_size = 0;
    struct node{
        int val;
        int index;
        int num;
    } heap[maxn];

    node top(){
        return heap[1];
    }
    void insert(int x,int index,int num){
        heap[++heap_size].val = x;
        heap[heap_size].index = index;
        heap[heap_size].num = num;
        int now = heap_size;
        while(now>1){
            int fa = now >> 1;
            if(heap[now].val<heap[fa].val){
                swap(heap[now], heap[fa]);
                now = fa;
                continue;
            }
            else
                break;
        }
    }
    void pop(){
        heap[1] = heap[heap_size--];
        int now = 1;
        while(now<=(heap_size>>1)){
            int ls = now << 1, rs = now << 1 | 1;
            int max_son = rs > heap_size ? ls : (heap[ls].val < heap[rs].val ? ls : rs);
            if(heap[now].val>heap[max_son].val){
                swap(heap[now], heap[max_son]);
                now = max_son;
                continue;
            }
            else
                break;
        }
    }
    int size(){
        return heap_size;
    }
    bool empty(){
        return heap_size == 0;
    }
} h;

int n, m;

int main()
{
    scanf("%d%d", &n,&m);
    for (int i = 1; i <= n;i++){
        scanf("%d%d%d", &f[i].a, &f[i].b, &f[i].c);
        f[i].index = i;
    }
    for (int i = 1; i <= n;i++){
        h.insert(f(i, 1),i,1);
        f[i].num = 1;
    }
    while(m--){
        int j = h.top().num+1, i = h.top().index;
        printf("%d ", h.top().val);
        h.pop();
        h.insert(f(i, j),i,j);
    }
    return 0;
}