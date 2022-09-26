//*二叉搜索树模板
#include <cstdio>

const int maxn = 1e4+10;
const int INF = 0x7fffffff;

int n, root, cnt;

struct BST{
    struct Node{
        int ls, rs;
        int size, val, num;

        Node(int l = 0,int r = 0,int s = 0,int v = 0){  //初始化一个节点
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

    int rank(int x, int root){
        if(root){
            if(x<t[root].val)
                return rank(x, t[root].ls);
            else if(x>t[root].val)
                return rank(x, t[root].rs) + t[t[root].ls].size + t[root].num;
            else
                return t[t[root].ls].size + 1;
        }
        return 1;
    }

    int kth(int x, int root){
        if(x==0)
            return -INF;
        if(x<=t[t[root].ls].size)
            return kth(x, t[root].ls);
        else if(x<=t[t[root].ls].size+t[root].num)
            return t[root].val;
        else
            return kth(x - t[t[root].ls].size - t[root].num, t[root].rs);
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
        update(root);
    }
} BST;


int main(){
    scanf("%d", &n);

    //由题意，先插入正无穷
    BST.init();

    while(n--){
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch(opt){ 
            case 1:
                printf("%d\n", BST.rank(x, root));
                break;
            case 2:
                printf("%d\n", BST.kth(x, root));
                break;
            case 3:
                printf("%d\n", BST.kth(BST.rank(x, root) - 1, root));
                break;
            case 4:
                printf("%d\n", BST.kth(BST.rank(x + 1, root), root));
                break;
            case 5:
                BST.insert(x, root);
                break;
        }
    }
    return 0;
}