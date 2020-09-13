#include <cstdio>
using namespace std;

int a;
int cnt=1;

int main()
{
    scanf("%d", &a);
    while(a>1){ 
        a/=2;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}