#include <cstdio>
using namespace std;

bool leap(int n)
{
    if (n % 4 == 0 && n % 100 != 0)
        return true;
    if (n % 100 == 0 && n % 400 == 0)
        return true;
    return false;
}

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int year, month;
    scanf("%d%d", &year, &month);
    if (leap(year))
    {
        if (month == 2)
            day[2]++;
    }
    printf("%d", day[month]);
    return 0;
}