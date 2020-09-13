#include <cstdio>

void work() {
    char c;     //!乱用全局必爆零
    scanf("%c", &c);
    if(c!='!')
        work();
    printf("%c", c);
    return;
}

int main()
{
    work();
    return 0;
}