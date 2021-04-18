#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 55;
int n;
char a[maxn];

int main(){
    scanf("%d%s", &n, a);
    for (int i = 0; i < strlen(a); i++)
        a[i] = (a[i]-'a'+n)%26+'a';
    printf("%s", a);
    return 0;
}