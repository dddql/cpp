#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1e3 + 50;

struct stu{
    char name[15];
    int ch;
    int ma;
    int en;
    int tot;
} s[maxn];

int n;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%s%d%d%d", s[i].name, &s[i].ch, &s[i].ma, &s[i].en);
        s[i].tot = s[i].ch + s[i].ma + s[i].en;
    }
    for (int i = 1; i < n;i++)
        for (int j = i + 1; j <= n;j++)
            if(abs(s[i].ch-s[j].ch)<=5&&abs(s[i].ma-s[j].ma)<=5&&abs(s[i].en-s[j].en)<=5&&abs(s[i].tot-s[j].tot)<=10)
                printf("%s %s\n", s[i].name, s[j].name);
    return 0;
}