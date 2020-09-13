#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
    int s, v;
    scanf("%d%d", &s, &v);
    int time_walk = ceil(s * 1.0 / v) + 10;
    int from_zero = 60 * (24 + 8) - time_walk;
    int hh = (from_zero / 60) % 24;
    int mm = from_zero % 60;
    printf("%02d:%02d", hh, mm);
    return 0;
}