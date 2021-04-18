#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1e3 + 5;

struct stud{
    char name[30];
    int ch;
    int ma;
    int en;
    int idx;
} stu[maxn];

stack<int> s;
int n;
int tot[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        stu[i].idx = i;
        scanf("%s%d%d%d", stu[i].name, &stu[i].ch, &stu[i].ma, &stu[i].en);
        tot[i] = stu[i].ch + stu[i].ma + stu[i].en;
        if(s.empty()||tot[i]>tot[s.top()])
            s.push(i);
    }
    printf("%s %d %d %d", stu[s.top()].name, stu[s.top()].ch, stu[s.top()].ma, stu[s.top()].en);
    return 0;
}