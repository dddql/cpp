#include <cstdio>

const int maxn = 1e3;

int n;

struct stu{
    char name[30];
    int age;
    int score;
} s[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%s%d%d", s[i].name, &s[i].age, &s[i].score);
    for (int i = 1; i <= n;i++){
        s[i].score = s[i].score + s[i].score/5;
        if(s[i].score>600)
            s[i].score = 600;
        printf("%s %d %d\n", s[i].name, s[i].age + 1, s[i].score);
    }
    return 0;
}