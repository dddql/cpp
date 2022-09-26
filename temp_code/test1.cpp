#include <cstdio>

int i = 5;

int main(){
    printf("%d\n", i);
    printf("%c\n", (char)48);
    printf("%c\n", (char)(('5' - '1')+48));
    char c = (char)((char)i) - ((char)0);
    putchar((char)((char)i) - ((char)0));
    return 0;
}