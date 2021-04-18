#include <cstdio>
#include <algorithm>
using namespace std;

int N, S = 0, B;
int h[20050];

bool cmp(int a,int b){
    return a > b;
}

int main()
{
    //freopen("P2676_3.in", "r", stdin);
    scanf("%d%d", &N, &B);
    for (int i = 1; i <= N;i++)
        scanf("%d", &h[i]);
    sort(h + 1, h + N + 1, cmp);
    for (int i = 1; i <= N;i++){
        S += h[i];
        if(S>=B){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}