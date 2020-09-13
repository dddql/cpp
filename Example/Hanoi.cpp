#include <cstdio>

int n;

void hanoi(int n, char a, char b, char c) {
    if(n){
        hanoi(n - 1, a, c, b);
        printf("%d %c %c\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}