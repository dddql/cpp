//*这道题在洛谷上要用DP
#include <cstdio>

int s[1001],k;
int min = 30000;
int h;

int main()
{
    while(scanf("%d",&h)!=EOF){
        for (int i = 1; i <= s[0];i++)
            if(s[i]>=n&&s[i]<min){
                min = s[i];
                k = i;
            }
        if(k==0)
            s[++s[0]] = n;
        else{
            s[k] = n;
            k = 0;
            min = 30000;
        }
    }
    printf("%d", s[0]);
    return 0;
}