#include <cstdio>
#include <cmath>
using namespace std;

int t;
int a, b, c;

int solve(int a, int b, int c){
    int t_l, t_r;
    t_l = a - 1;
    t_r = abs(b - c) + (c - 1);
    if(t_l<t_r)
        return 1;
    else if(t_l>t_r)
        return 2;
    else
        return 3;
}

int main(){
    scanf("%d", &t);
    for (int i = 1; i <= t;i++){
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n",solve(a, b, c));
    }
    return 0;
}