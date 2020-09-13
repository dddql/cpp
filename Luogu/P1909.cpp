#include <cstdio>
#include <cmath>

int main()
{
    int n, cost[3], min = 10000000;
    float contain, each_cost;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        scanf("%f%f", &contain, &each_cost);
        cost[i] = (ceil(n / contain) * each_cost);
    }
    for (int i = 0; i < 3; i++)
    {
        if (cost[i] < min)
            min = cost[i];
    }
    printf("%d", min);
    return 0;
}