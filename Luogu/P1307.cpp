#include <cstdio>
#include <cstring>

char n[10];
int len;
bool last=true;

void output(int x) {
    for (int i = len-1; i >= x;i--){
        for (int j = i; j <= len - 1;j++){
            if(n[j]!='0')
                last = false;
        }
        if (!last)
            printf("%c", n[i]);
    }
}
int main()
{
    scanf("%s", n);
    len = strlen(n);
    if(n[len-1]!='0')
        last = false;
    if(n[0]!='-')
        output(0);
    else{
        printf("-");
        output(1);
    }
    return 0;
}