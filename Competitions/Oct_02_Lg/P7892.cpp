#include <cstdio>

int t;
int n,m;

int main(){
    scanf("%d", &t);
    for (int i = 1; i <= t;i++){
        scanf("%d%d", &n, &m);
        if(m<(((int)sqrt(n)+1)*((int)sqrt(n)+1))){
            printf("Miss\n");
            return 0;
        }
        else
            printf("%d")

    }
        return 0;
}