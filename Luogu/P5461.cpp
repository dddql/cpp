/*
#include <cstdio>

int a[1050][1050], n;

void cal(int x, int y, int n)
{
    if (n == 0)
        a[x][y] = 1;
    else
    {
        cal(x, y + (1 << n - 1), n - 1);
        cal(x + (1 << n - 1), y, n - 1);
        cal(x + (1 << n - 1), y + (1 << n - 1), n - 1);
    }
}

void output()
{
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < 1 << n; j++)
            printf("%d%c", a[i][j], j == (1 << n) - 1 ? '\n' : ' ');
}
int main()
{
    scanf("%d", &n);
    cal(0, 0, n);
    output();
    return 0;
}*/
#include <cstdio>

const int maxn = 1e3 + 50;

int n;
int map[maxn][maxn];

void cal(int x,int y,int n){
    if(n=0)
        map[x][y] = 1;
    else{
        cal(x, y + (1 << n - 1), n - 1);
        cal(x + (1 << n - 1), y, n - 1);
        cal(x + (1 << n - 1), y + (1 << n - 1), n - 1);
    }
}

void print(){
    for (int i = 0; i < 1 << n;i++)
        for (int j = 0; j < 1 << n;j++)
            printf("%d%c", map[i][j], j == (1 << n)-1 ? '\n' : '\0');
}

int main(){
    scanf("%d", &n);
    cal(0, 0, n);
    print();
    return 0;
}