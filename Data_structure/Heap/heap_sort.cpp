//*堆排序模板/优先队列
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+10;

struct heap{
    int heap_size = 0;
    int heap[maxn];

    int top(){
        return heap[1];
    }
    void insert(int x){
        heap[++heap_size] = x;
        int now = heap_size;
        while(now>1){
            int fa = now >> 1;
            if(heap[now]<heap[fa]){
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
            int max_son = rs > heap_size ? ls : (heap[ls] < heap[rs] ? ls : rs);
            if(heap[now]>heap[max_son]){
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

int n;
int a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
        h.insert(a[i]);
    }
    while(!h.empty()){
        printf("%d ", h.top());
        h.pop();
    }
    return 0;
}