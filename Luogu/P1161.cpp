#include <cstdio>
#include <cstring>
using namespace std;

const int maxT = 2e6+100;
const int maxn = 5e3+50;

int n, T;
bool map[maxT];
double a[maxn];
int t[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%lf%d", &a[i], &t[i]);
        T += t[i];
        for (int j = 1; j <= t[i];j++)
            map[(int)(a[i] * j)] = !map[(int)(a[i] * j)];
    }
    for (int i = 1; i <= maxT; i++)
        if (map[i] == true)
        {
            printf("%d", i);
            return 0;
        }
    return 0;
}