#include <cstdio>

int n;

struct stu{
    int id;
    int score_aca;
    int score_ext;
    float sum;
};
stu s[1005];

bool check(stu s){
    if(s.score_aca+s.score_ext>140&&s.sum>=80)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d%d", &s[i].id, &s[i].score_aca, &s[i].score_ext);
        s[i].sum = 0.7 * s[i].score_aca + 0.3 * s[i].score_ext;
        if(check(s[i]))
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }
    return 0;
}