//*
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 10000
using namespace std;

int a[maxn], b[maxn], c[maxn];

void read(int a[]){
    char s[maxn];
    scanf("%s", s);
    int len = strlen(s);
    a[0] = (len - 1) / 4 + 1;
    for (int i = 0; i < len;i++){
        int j = (len - i + 3) / 4;
        a[j] = a[j] * 10 + s[i] - '0';
    }
}

void add(int a[],int b[],int c[]){
    int len = max(a[0], b[0]);
    for (int i = 1; i <= len;i++){
        c[i] += a[i] + b[i];
        if(c[i]>=10000){
            c[i + 1] += c[i] / 10000;
            c[i] %= 10000;
        }
    }
    c[0] = c[len+1] == 0 ? len : len+1;
}

void mul(int a[],int b[],int c[]){
    int len = a[0] + b[0];
    for (int i = 1; i <= len;i++){
        for (int j = 1; j <= i;j++){
            c[i] += a[j] * b[i + 1 - j];
            if(c[i]>=10000){
                c[i + 1] = c[i] / 10000;
                c[i] %= 10000;
            }
        }
    }
    for (; !a[len];)
        len--;
    c[0] = len;
}

void mul_short(int a[],int b){
    int len = a[0], x = 0, i;
    for (i = 1; i <= len;i++){
        a[i] = a[i] * b + x;
        x = a[i] / 10000;
        a[i] %= 10000;
    }
    while(x){           //*判断最高位是否还需进位
        a[i++] = x % 10;
        x /= 10;
    }
    a[0] = i-1;         //*更新位数
}

void printnum(int cnt,int x){
    if(cnt==0)
        return;
    int t = x % 10;
    printnum(cnt - 1,x/10);
    printf("%d", t);
}

void print(int a[]){
    int len = a[0];
    printf("%d", a[len]);
    for (int i = len - 1; i >= 1;i--)
        printnum(4,a[i]);
}

int fac[5000];

int main()
{
    int n;
    scanf("%d", &n);
    fac[0] = fac[1] = 1;
    for (int i = 1; i <= n;i++)
        mul_short(fac, i);
    print(fac);

    /*
    read(a);
    read(b);
    add(a, b, c);
    print(c);*/
    return 0;
}