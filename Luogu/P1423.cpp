#include <cstdio>

float length = 2.0,step = 2, x;
int cnt=1;

int main()
{
    
    scanf("%f", &x);
    while (length < x)
    {
        step *= 0.98;
        length += step;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}