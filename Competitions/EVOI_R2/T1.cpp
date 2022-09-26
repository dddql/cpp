#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
string s;
int ut = INF, ue = INF;
int lt = -INF, le = -INF;
int up, low;
bool cb_u, cb_l, u, l;
char x;

void input(){
    int t = 0;
    cin >> s;
    if(s[2]=='='){
        t = atoi(s.substr(3, s.size() - 3).c_str());
        if(s[1]=='<')
            ue = min(ue, t), u = true;
        else
            le = max(le, t), l = true;
    }
    else{
        t = atoi(s.substr(2, s.size() - 2).c_str());
        if(s[1]=='<')
            ut = min(ut, t), u = true;
        else
            lt = max(lt, t), l = true;
    }
}

void work(){
    if(lt>=le){
        low = lt;
        cb_l = false;
    }
    else{
        low = le;
        cb_l = true;
    }
    if(ut<=ue){
        up = ut;
        cb_u = false;
    }
    else{
        up = ue;
        cb_u = true;
    }
}

void print(){
    if(u&&l){
        if(up<low){
            printf("No Answer!");
            return;
        }
        if(up==low){
            if(!(cb_l&&cb_u))
                printf("No Answer!");
            else
                printf("%c=%d", x, up);
        }
        else{
            printf("%d", low);
            if(cb_l)
                printf("<=");
            else
                printf("<");
            printf("%c", x);
            if(cb_u)
                printf("<=");
            else
                printf("<");
            printf("%d", up);
        }
    }
    else if(u){
        printf("%c", x);
        if(cb_u)
            printf("<=");
        else
            printf("<");
        printf("%d", up);
    }
    else if(l){
        printf("%c", x);
        if(cb_l)
            printf(">=");
        else
            printf(">");
        printf("%d", low);
    }
}

int main(){
    scanf("%d", &n);
    getchar(), x = getchar(), getchar();
    for (int i = 1; i <= n;i++)
        input();
    work();
    print();
    return 0;
}