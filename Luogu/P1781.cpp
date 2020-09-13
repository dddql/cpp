#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct candidate{
    string vote;
    int num;
    int len;
};
candidate cand[21];

bool cmp(candidate a,candidate b) {
    if(a.len>b.len)
        return true;
    if(a.len==b.len&&a.vote>b.vote)
        return true;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        cin>>cand[i].vote;
        cand[i].num = i;
        cand[i].len = cand[i].vote.size();
    }
    sort(cand + 1, cand + n + 1, cmp);
    printf("%d\n%s", cand[1].num, cand[1].vote.c_str());
    return 0;
}