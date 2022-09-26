#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    int ans = max(max(a, b), c);
    printf("%d", ans);
    return 0;
}