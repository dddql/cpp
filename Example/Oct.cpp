#include <cstdio>

int oct;

void work(int n) {
    if(n==0)        //*如果为零，说明（上一层）的n已经小于8
        return;
    work(n/8);
    printf("%d", n % 8);
}
int main()
{
    scanf("%d", &oct);
    work(oct);
    return 0;
}