#include <cstdio>

int per, num, aft;
int adt[1000], egg[1000];

int cal(int per, int num, int aft) {
    if(aft<per)
        return 0;
    for (int i = 1; i <= per;i++){
        adt[i] = 1;
        egg[i] = 0;
    }
    for (int i = per+1; i <= aft+1; i++)
    {
        egg[i] = num * adt[i - per];
        adt[i] = adt[i - 1] + egg[i - 2];
    }
    return adt[aft+1];
}
int main()
{
    scanf("%d%d%d", &per, &num, &aft);
    printf("%d", cal(per, num, aft));
    return 0;
}