/*
法一：f[i][j]表示以i为根，节点量为j的子树最大苹果数
    f[i][j] = f[l[i]][k] + f[r[i]][j-1-k] + a[i]
    f[i][0] = 0, a[1] = 0
    求f[i][Q]
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
    int ls;
    int next;
    int num;
};

vector<edge> e[maxn];

int dfs(int x){

}

int main(){
    
    return 0;
}