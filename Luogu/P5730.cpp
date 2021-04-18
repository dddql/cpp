#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 105;

int n;
char a[maxn];
char ans[10][5][3] = {
    {{'X', 'X', 'X'}, {'X', '.', 'X'}, {'X', '.', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}},
    {{'.', '.', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}},
    {{'X', 'X', 'X'}, {'.', '.', 'X'}, {'X', 'X', 'X'}, {'X', '.', '.'}, {'X', 'X', 'X'}},
    {{'X', 'X', 'X'}, {'.', '.', 'X'}, {'X', 'X', 'X'}, {'.', '.', 'X'}, {'X', 'X', 'X'}},
    {{'X', '.', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}},
    {{'X', 'X', 'X'}, {'X', '.', '.'}, {'X', 'X', 'X'}, {'.', '.', 'X'}, {'X', 'X', 'X'}},
    {{'X', 'X', 'X'}, {'X', '.', '.'}, {'X', 'X', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}},
    {{'X', 'X', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}, {'.', '.', 'X'}},
    {{'X', 'X', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}},
    {{'X', 'X', 'X'}, {'X', '.', 'X'}, {'X', 'X', 'X'}, {'.', '.', 'X'}, {'X', 'X', 'X'}}};

int main(){
    scanf("%d", &n);
    if(getchar()=='\r')
        getchar();
    for (int i = 1; i <= n;i++)
        scanf("%c", &a[i]);
    for (int i = 0; i < 5;i++){
        for (int j = 1; j <= n;j++){
            for (int k = 0; k < 3;k++)
                printf("%c", ans[a[j] - '0'][i][k]);
            if(j!=n)
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
/*
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
X.X...X...X...X.X.X.X...X.....X.X.X.X.X
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
X.X...X.X.....X...X...X.X.X...X.X.X...X
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX*/