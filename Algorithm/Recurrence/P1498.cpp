#include <cstdio>

int line, column, n;
char c[3005][3005];

void init(){
    for (int i = 1; i <= 3000;i++)
        for (int j = 1; j <= 3000;j++)
            c[i][j] = ' ';
    c[1][2] = c[1][3] = '_';
    c[1][1] = c[2][2] = '\\';
    c[1][4] = c[2][3] = '/';
    line = 2, column = 4;
}

void copy_right(){
    for (int i = 1; i <= line;i++)
        for (int j = 1; j <= column;j++)
            c[i][j + column] = c[i][j];
}

void copy_down(){
    for (int i = 1; i <= line;i++)
        for (int j = 1; j <= column;j++)
            c[i + line][j + column / 2] = c[i][j];
}

void draw(){
    scanf("%d", &n);
    for (int i = 2; i <= n;i++){
        copy_right();
        copy_down();
        line *= 2;
        column *= 2;
    }
}

void print(){
    for (int i = line; i >= 1;i--,puts(""))
        for (int j = 1; j <= column;j++){
            if(c[i][j]=='\\')
                printf("/");
            else if(c[i][j]=='/')
                printf("\\");
            else if(c[i][j]==' '||c[i][j]=='_')
                printf("%c", c[i][j]);
        }
}
int main()
{
    init();

    draw();

    print();

    return 0;
}