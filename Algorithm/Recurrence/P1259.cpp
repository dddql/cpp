#include <cstdio>

int n, st;
char c[205];

void print(){
    for (int i = 1; i <= 2 * n + 2;i++)
        printf("%c", c[i]);
    printf("\n");
}

void init(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        c[i] = 'o';
    for (int i = n + 1; i <= 2 * n;i++)
        c[i] = '*';
    c[2 * n + 1] = c[2 * n + 2] = '-';
    st = 2 * n + 1;
    print();
}

void swap(char &a,char &b){
    char t = a;
    a = b;
    b = t;
}

void _swap(int k){
    for (int i = 0; i <= 1;i++)
        swap(c[st + i], c[k + i]);
    st = k;
    print();
}

void move(int n){
    if(n==4){
        _swap(4);
        _swap(8);
        _swap(2);
        _swap(7);
        _swap(1);
    }
    else{
        _swap(n);
        _swap(2 * n - 1);
        move(n - 1);
    }
}

int main(){
    init();
    move(n);
    return 0;
}