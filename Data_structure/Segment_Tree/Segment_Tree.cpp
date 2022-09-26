#include <cstdio>
#define maxn 100010
using namespace std;

typedef long long LL;
LL n, m, op;
LL a[maxn], d[maxn<<2], b[maxn<<2];
LL ans[maxn],k;

void push_up(LL p){        //*更新
    d[p] = d[p << 1] + d[p << 1 | 1];
}

void push_down(LL p){      //*下传
    d[p << 1] += b[p] * (m - s + 1);
    d[p << 1 | 1] += b[p] * (t - m);
    b[p << 1] += b[p];            //*将标记下传给子节点
    b[p << 1 | 1] += b[p];
    b[p] = 0;                    //*清空当前节点的标记
}

//?建树
void build(LL s, LL t, LL p) {
    //todo 对 [s,t] 区间建立线段树,当前根的编号为 p
    //*递归建树，边界条件为区间长度为1，此时 d[i]=a[s]=a[t]
    if(s==t){
        d[p] = a[s];
        return;
    }
    LL m = (s + t) >> 1;

    //todo 递归对左右区间建树
    //*左儿子序号为p*2，右儿子序号为p*2+1
    build(s, m, p << 1);
    build(m + 1, t, p << 1 | 1);

    //*根节点大小为左右儿子节点之和
    push_up(p);
}

//?区间查询
LL getsum(LL l, LL r, LL s, LL t, LL p) {
    //*[l,r] 为查询区间,[s,t] 为当前节点包含的区间,p 为当前节点的编号
    if(s>=l&&t<=r)
        return d[p];
    //*当前区间为询问区间的子集时直接返回当前区间的和
    
    LL m = (s + t) >> 1;

    LL sum = 0;

    //*如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    if (b[p])
        push_down(p);
    //*如果左儿子代表的区间 [l,m] 与询问区间有交集,则递归查询左儿子
    if(l<=m)
        sum += getsum(l, r, s, m, p << 1);
    //*如果右儿子代表的区间 [m+1,r] 与询问区间有交集,则递归查询右儿子
    if(r>m)
        sum += getsum(l, r, m + 1, t, p << 1 | 1);

    return sum;
}

//?区间修改(增加)
void update(LL l, LL r, LL c, LL s, LL t, LL p) {
    //*[l,r] 为修改区间,c 为被修改的元素的变化量,
    //*[s,t] 为当前节点包含的区间,p为当前节点的编号

    //*当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    if(s>=l&&t<=r){
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }

    LL m = (s + t) >> 1;

    //*如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    if(b[p]&&s!=t)
        push_down(p);
    if(l<=m)
        update(l, r, c, s, m, p << 1);
    if(m<r)
        update(l, r, c, m + 1, t, p << 1 | 1);
    push_up(p);
}

void op_1() {           //*区间修改
    LL x, y, k;
    scanf("%lld%lld%lld", &x, &y, &k);
    update(x, y, k, 1, n, 1);
}

void op_2() {           //*区间查询
    LL x, y;
    scanf("%lld%lld", &x, &y);
    ans[++k]=getsum(x, y, 1, n, 1);
    return;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (LL i = 1; i <= n;i++)
        scanf("%lld", &a[i]);

    build(1, n, 1);

    for (LL i = 1; i <= m;i++){
        scanf("%lld", &op);
        switch (op)
        {
        case 1:
            op_1();
            break;
        case 2:
            op_2();
            break;
        default:
            break;
        }
    }

    for (LL i = 1; i <= k;i++)
        printf("%lld\n", ans[i]);
    return 0;
}