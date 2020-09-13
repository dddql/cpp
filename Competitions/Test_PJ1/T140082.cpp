#include <cstdio>

int main()
{
    int RPM, Dam;
    scanf("%d%d", &RPM, &Dam);
    float DPS = RPM * Dam * 1.0 / 60;
    printf("%.2f\n", DPS);
    if (DPS >= 180)
        printf("Good");
    else
        printf("Bad");
    return 0;
}