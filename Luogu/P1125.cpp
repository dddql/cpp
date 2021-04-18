#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;

int maxx = -1, minn = 105;
char w[maxn];
int a[26];

bool is_prime(int x){
    bool flag = true;
    if(x==0||x==1)
        return false;
    else if(x==2||x==3)
        return true;
    else{
        for (int i = 2; i * i <= x;i++)
            if(!(x%i))
                flag = false;
    }
    return flag;
}

int main(){
    scanf("%s",w);
    int len = strlen(w);
    for (int i = 0; i < len;i++)
        a[w[i] - 'a']++;
    for (int i = 0; i < 26;i++){
        maxx = maxx < a[i] ? a[i] : maxx;
        minn = (minn > a[i] && a[i]) ? a[i] : minn;
    }
    if(is_prime(maxx-minn))
        printf("Lucky Word\n%d", maxx - minn);
    else
        printf("No Answer\n%d", 0);
    return 0;
}