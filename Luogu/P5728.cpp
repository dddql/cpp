#include <cstdio>
#include <cmath>
using namespace std;

struct stu{
    int ch;
    int ma;
    int en;
    int tot;
} s[1005];

int n, p;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d%d", &s[i].ch, &s[i].ma, &s[i].en);
        s[i].tot = s[i].ch + s[i].ma + s[i].en;
    }
    for (int i = 1; i <= n;i++)
        for (int j = i+1; j <= n;j++)
            if(abs(s[i].ch-s[j].ch)<=5&&abs(s[i].ma-s[j].ma)<=5&&abs(s[i].en-s[j].en)<=5&&abs(s[i].tot-s[j].tot)<=10)
                p++;
    printf("%d", p);
    return 0;
}