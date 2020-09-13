#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int line,cnt;
struct candidate{
    int num;
    int score;
};
candidate cand[5000];

bool cmp(candidate a, candidate b) {
    if(a.score>b.score)
        return true;
    else if(a.score==b.score&&a.num<b.num)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d%d", &cand[i].num, &cand[i].score);
    sort(cand + 1, cand + n + 1, cmp);
    line = cand[(int)floor(m * 1.5)].score;
    for (int i = 1; cand[i].score >= line;i++)
        cnt++;
    printf("%d %d\n", line, cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d %d\n", cand[i].num, cand[i].score);
    return 0;
}