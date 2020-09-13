#include <cstdio>
#include <algorithm>
using namespace std;
int num[3];
int main()
{
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    sort(num, num+3);
    int gcd=1;
    for (int i=num[0];i>0;i--)
        if (num[0]%i==0&&num[2]%i==0){ 
            gcd=i;
            break;
        }
    printf("%d/%d", num[0]/gcd, num[2]/gcd);
    return 0;
}