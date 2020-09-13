#include <cstdio>
#include <cstring>

int n,ans;
int m[1050];

void read(int a[]){
    char s[1050];
    scanf("%s", s);
    int len = strlen(s);
    a[0] = len;
    for (int i = 1; i <= len;i++)
        a[i] = s[len - i] - '0';
}

int mod(int a[],int b){
    int len = a[0];
    int x = 0, c = 0;
    for (int i = len; i >= 1;i--){
        x = (a[i] + c * 10) / b;
        c = (a[i] + c * 10) % b;
    }
    return c;
}
int main()
{
    scanf("%d", &n);
    read(m);
    ans = mod(m, n);
    if(ans==0)
        ans = n;
    printf("%d\n", ans);
    return 0;
}