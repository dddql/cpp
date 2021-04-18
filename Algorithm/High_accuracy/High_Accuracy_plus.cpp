#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int LEN = 10010;
int a[LEN], b[LEN];
int c[LEN], d;                          //*d为余数

void clear(int a[]) {
    for (int i = 0; i < LEN; ++i) 
        a[i] = 0;
}

void read(int a[]){                     //*读入
    char s[LEN + 5];
    scanf("%s", s);
    int len = strlen(s);
    a[0] = ceil(len / 4);               //*压4位
    for (int i = 1; i <= len;i++){
        if(s[len-i]>='0'&&s[len-i]<='9'){
            int j = ceil((len - i) / 4);
            a[j] = a[j] * 10 + s[len-i] - '0';
        }
        else
            a[i] = s[len - i] - 'A' + 10;
    }
}

void add(int a[],int b[],int c[]){      //*加法
    clear(c);
    int len = max(a[0], b[0]);
    for (int i = 1; i <= len;i++){
        c[i] += a[i] + b[i];
        if(c[i]>=10){
            c[i + 1]++;
            c[i] %= 10;
        }
    }
}

void add_HEX(int a[],int b[],int c[]){  //*啊这，不会吧
    clear(c);
    int len = max(a[0], b[0]);
    for (int i = 1; i <= len;i++){
        c[i] += a[i] + b[i];
        if(c[i]>=16){
            c[i + 1]++;
            c[i] %= 16;
        }
        if(c[len+1])
            c[0] = len + 1;
        else
            c[0] = len;
    }
}

void do_sub(int a[],int b[],int c[]){   //*减法
    int len = max(a[0], b[0]);
    for(int i = 1;i <= len;i++){
        c[i] += a[i] - b[i];
        if(c[i]<0){
            c[i + 1]--;
            c[i] += 10;
        }
    }
}

bool cmp(int a[],int b[]){              //*判断a,b大小
    if(a[0]>b[0])                       //*保证大数减小数
        return true;
    else if(a[0]==b[0]){
        for (int i = 1; i <= a[0];i++){
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        }
    }
    else
        return false;
}

void sub(int a[],int b[],int c[]){      //*啊这。。。
    if(cmp(a, b))
        do_sub(a, b, c);
    else{
        printf("-");
        do_sub(b, a, c);
    }
}

void mul_short(int a[],int b,int c[]){  //*高乘低
    clear(c);
    int len = a[0];
    for (int i = 1; i <= len;i++){
        c[i] += a[i] * b;
        if(c[i]>10){
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

void multi(int a[],int b[],int c[]){    //*高乘高
    clear(c);
    int len = (a[0] + b[0]);
    for (int i = 1; i <= len;i++){
        for (int j = 1; j <= i;j++)
            c[i] += a[j] * b[i + 1 - j];
        if(c[i]>10000){
            c[i + 1] += c[i] / 10000;
            c[i] %= 10000;
        }
    }
}

void div_short(int a[],int b,int c[]){
    clear(c);

    int len = a[0];
    c[0] = len;
    int t=0;
    for (int i = len; i >= 1;i--){
        c[i] = (a[i] + t * 10) / b;
        t = (a[i] + t * 10) % b;
    }
    d = t;
}

void print(int a[]){                    //*输出答案
    int i;
    for (i = a[0]; i > 1;i--){
        if(a[i]!=0)
            break;
        a[0]--;
    }
    for (; i >= 1;i--){
        int cnt = 4;
        while(cnt--){
            int t = a[i];
        }
        printf("%c", 'A' + a[i] - 10);
    }
}

int main()
{
    read(a);
    read(b);

    add(a, b, c);

    print(c);
    return 0;
}