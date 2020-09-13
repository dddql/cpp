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
node s[100050];       //*结点池

int tot = 0;        //*记录已经使用了几个位置
int index[100050] = {0};

int N, M;

void ins_front(int x,int y){
    int now = index[x];
    s[++tot] = node(y, s[now].pre, now);
    s[s[now].pre].nxt = tot;
    s[now].pre = tot;
    index[y] = tot;
}

void ins_back(int x,int y){ //*把y插在x后面
    int now = index[x];      //*现在s[now].key = x
    s[++tot] = node(y, now, s[now].nxt);
    //*y的前驱为now，后继为s[now].nxt
    s[s[now].nxt].pre = tot;
    //*更新原先now的后继的pre
    s[now].nxt = tot;
    index[y] = tot;
}

void del(int x){
    int now = index[x];
    int lf = s[now].pre, rt = s[now].nxt;
    s[lf].nxt = rt;
    s[rt].pre = lf;
    index[x] = 0;
}

int main()
{
    s[0] = node();
    ins_back(0, 1);

    scanf("%d", &N);
    int k, p;
    for (int i = 2; i <= N;i++){
        scanf("%d%d", &k, &p);
        p ? ins_back(k, i) : ins_front(k, i);
    }

    scanf("%d", &M);
    int t;
    for (int i = 1; i <= M;i++){
        scanf("%d", &t);
        if(index[t])
            del(t);
    }

    int now = s[0].nxt;
    while(now){
        printf("%d ", s[now].key);
        now = s[now].nxt;
    }
    return 0;
}