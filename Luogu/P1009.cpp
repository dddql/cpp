#include <cstdio>

int n,len=1;
int sum[51][100];

void fac(int k) {
    for (int i = 1; i <= len;i++)
        sum[k][i] = sum[k - 1][i] * k;
    for (int i = 1; i <= len;i++)
        if(sum[k][i]>=10){
            sum[k][i + 1] += sum[k][i] / 10;
            sum[k][i] %= 10;
            if(sum[k][len+1])
                len++;
        }
}

void mul_short(int a[], int c) {
    
}
int main()
{
    scanf("%d", n);
    for (int i = 1; i <= k;i++)
        fac(i);
    
    return 0;
}