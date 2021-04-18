#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 12;

int n;
char map[maxn][maxn];
char last[maxn][maxn];

bool check(char a[][12], char b[][12]){
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            if(a[i][j]!=b[i][j])
                return false;
    return true;
}

bool trans_1(){
    char c[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            c[j][n + 1 - i] = map[i][j];
    return check(c, last);
}

bool trans_2(){
    char c[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            c[n + 1 - i][n + 1 - j] = map[i][j];
    return check(c, last);
}

bool trans_3(){
    char c[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            c[n + 1 - j][i] = map[i][j];
    return check(c, last);
}

bool trans_4(){
    char c[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            c[i][n + 1 - j] = map[i][j];
    return check(c, last);
}

bool trans_5(){
    char c[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            c[i][n + 1 - j] = map[i][j];
    char d[maxn][maxn];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            d[j][n + 1 - i] = c[i][j];
    if(check(d,last))
        return true;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            d[n + 1 - i][n + 1 - j] = c[i][j];
    if(check(d,last))
        return true;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            d[n + 1 - j][i] = c[i][j];
    return check(d, last);
}

bool trans_6(){
    return check(map, last);
}

int work(){
    if(trans_1())
        return 1;
    if(trans_2())
        return 2;
    if(trans_3())
        return 3;
    if(trans_4())
        return 4;
    if(trans_5())
        return 5;
    if(trans_6())
        return 6;
    return 7;
}

void skip(){
    if(getchar()!='\n')
        getchar();
}

int main(){
    scanf("%d", &n), skip();
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            scanf("%c", &map[i][j]);
        skip();
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            scanf("%c", &last[i][j]);
        skip();
    }
    printf("%d",work());
    return 0;
}