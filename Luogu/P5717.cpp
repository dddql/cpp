#include <cstdio>
#include <algorithm> //*头文件千万不要忘！！！
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int d[4] = {0, a, b, c};
    sort(d + 1, d + 4);

    if (d[1] + d[2] <= d[3])
    {
        printf("Not triangle\n");
        return 0;
    }
    if (pow(d[1], 2) + pow(d[2], 2) == pow(d[3], 2))
        printf("Right triangle\n");
    if (pow(d[1], 2) + pow(d[2], 2) > pow(d[3], 2))
        printf("Acute triangle\n");
    if (pow(d[1], 2) + pow(d[2], 2) < pow(d[3], 2))
        printf("Obtuse triangle\n");
    if (d[1] == d[2] || d[2] == d[3] || d[1] == d[3])
        printf("Isosceles triangle\n");
    if (d[1] == d[2] && d[2] == d[3])
        printf("Equilateral triangle\n");

    return 0;
}