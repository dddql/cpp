#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 4e4+50;
char text[maxn], line[maxn];
int n, num, c;

int main(){
    scanf("%s", line);
    strcat(text, line);
    n = strlen(line);
    for (int i = 2; i <= n;i++){
        scanf("%s", line);
        strcat(text, line);
    }
    printf("%d ", n);
    for (int i = 0, c = '0'; i < strlen(text); i++)
    {
        while(text[i]==c){
            num++, i++;
        }
        c = text[i];
        printf("%d ", num);
        num = 1;
    }
    return 0;
}