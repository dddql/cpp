#include <cstdio>

int k;
int sum, day;

int main()
{
    scanf("%d", &k);
    for(int i=1;;i++){ 
        for(int j=1;j<=i;j++){ 
            sum+=i;
            day++;
            if (day==k) { 
                printf("%d", sum);
                return 0;
            }
        }
    }

    return 0;
}