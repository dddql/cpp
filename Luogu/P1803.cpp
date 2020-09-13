#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans, x = -1;
int index[100005];
struct segment{
    int l;
    int r;
};
segment s[100005];

bool cmp(int a,int b){
    if(s[a].r!=s[b].r)
        return s[a].r < s[b].r;
    else
        return s[a].l < s[b].l;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d", &s[i].l, &s[i].r);
        index[i] = i;
    }
    sort(index + 1, index + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if(x<=s[index[i]].l){
            ans++;
            x = s[index[i]].r;
        }
    }
    printf("%d", ans);
    return 0;
}
