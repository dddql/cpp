#include <cstdio>

int n, x;
int temp,num,cnt;

int main()
{
    scanf("%d%d", &n, &x);
    for(int i=1;i<=n;i++){ 
        temp=i;
        while(temp!=0){ 
            num=temp%10;
            if(num==x)
                cnt++;
            temp/=10;
        }
    }
    printf("%d", cnt);
    return 0;
}