#include <cstdio>
using namespace std;

int n,MIN=1001;
int num;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){ 
        scanf("%d", &num);
        if (num<MIN) MIN=num;
    }
    printf("%d", MIN);
    return 0;
}