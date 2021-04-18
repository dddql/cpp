#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e3;

vector<int> e[maxn];

int m, n;
int begin;
bool visit[maxn];
int path[maxn];

void print(int index){
    for (int i = 1; i < index;i++)
        printf("%d->", path[i]);
    printf("%d\n", path[index]);
}

void hamilton(int current,int index){
    path[index] = current;

    if(current==begin&&index>3)
        print(index);

    else {
        for (int j = 0; j < e[current].size();j++){
            if (e[current][j] == begin &&index>2)
                hamilton(e[current][j], index + 1);
            else if(e[current][j]>current&&!visit[e[current][j]]){
                visit[e[current][j]] = true;
                hamilton(e[current][j], index + 1);
                visit[e[current][j]] = false;
            }
        }
    }
    return;
}

void dfs(){
    for (int i = 1; i <= n - 2;i++){
        begin = i;
        hamilton(i, 1);
    }
    return;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs();
    return 0;
}
