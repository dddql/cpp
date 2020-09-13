//*数组模拟双向链表
#include <cstdio>

struct node{
    int pre, nxt;       //*记录前驱和后继
    int key;            //*记录节点的值
    node(int _key = 0,int _pre = 0,int _nxt = 0){
        pre = _pre;
        nxt = _nxt;
        key = _key;
    }
};
node s[1005];       //*结点池

int tot = 0;        //*记录已经使用了几个位置

int find(int x){    //*查找x的节点编号，遍历链表
    int now = 1;
    while(now&&s[now].key!=x)
        now = s[now].nxt;
    return now;
}

void ins_front(int x,int y){
    int now = find(x);
    s[++tot] = node(y, s[now].pre, now);
    s[s[now].pre].nxt = tot;
    s[now].pre = tot;
}

void ins_back(int x,int y){ //*把y插在x后面
    int now = find(x);      //*现在s[now].key = x
    s[++tot] = node(y, now, s[now].nxt);
    //*y的前驱为now，后继为s[now].nxt
    s[s[now].nxt].pre = tot;
    //*更新原先now的后继的pre
    s[now].nxt = tot;
}

int ask_front(int x){
    int now = find(x);
    return s[s[now].pre].key;
}

int ask_back(int x){
    int now = find(x);
    return s[s[now].nxt].key;
}

void del(int x){
    int now = find(x);
    int lf = s[now].pre, rt = s[now].nxt;
    s[lf].nxt = rt;
    s[rt].pre = lf;
}

int main()
{
    
    return 0;
}