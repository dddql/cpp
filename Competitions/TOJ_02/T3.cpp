//*二叉搜索树模板
#include <cstdio>

const int maxn = 10010;
const int INF = 0x7fffffff;

int n, root = 1, cnt = 1;

struct Node{
    int left, right;
    int size, value, num;

    Node(int l=0,int r=0,int s=0,int v=0){
        left = l, right = r, size = s, value = v;
        num = 1;
    }

} t[maxn];

inline void update(int root){
    t[root].size = t[t[root].left].size + t[t[root].right].size + t[root].num;
}

int rank(int x,int root){
    if(root){
        if(x<t[root].value)
            return rank(x, t[root].left);

        else if(x>t[root].value)
            return rank(x, t[root].right) + t[t[root].left].size + t[root].num;

        else
            return t[t[root].left].size + 1;
    }
    return 1;
}

int kth(int x,int root){
    if(x<=0)
        return -INF;

    if(x<=t[t[root].left].size)
        return kth(x, t[root].left);

    else if(x<=t[t[root].left].size+t[root].num)
        return t[root].value;

    else
        return kth(x - t[t[root].left].size - t[root].num, t[root].right);
}

void insert(int x,int &root){
    if(x<t[root].value)
        if(!t[root].left)
            t[t[root].left = ++cnt] = Node(0, 0, 1, x);
        else
            insert(x, t[root].left);

    else if(x==t[root].value)
        t[root].num++;

    else
        if(!t[root].right)
            t[t[root].right = ++cnt] = Node(0, 0, 1, x);
        else
            insert(x, t[root].right);

    update(root);
}

int main(){
    //freopen("3.in", "r", stdin);

    scanf("%d", &n);
    t[root] = Node(0, 0, 1, INF);

    while(n--){
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch(opt){
            case 1:
                printf("%d\n", rank(x, root));
                break;
            case 2:
                printf("%d\n", kth(x, root));
                break;
            case 3:
                printf("%d\n", kth(rank(x, root) - 1, root));
                break;
            case 4:
                printf("%d\n", kth(rank(x + 1, root), root));
                break;
            case 5:
                insert(x, root);
                break;
        }
    }
    return 0;
}