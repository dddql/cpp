#include <cstdio>
#include <cmath>
#define ex 1e-11
using namespace std;

double l, r;
double ans;

double f(double x){
    return exp(x * log(2)) + exp(x * log(3)) - exp(x * log(4));
}

int main()
{
    scanf("%lf%lf", &l, &r);
    while(r-l > ex){
        double mid = (l + r) / 2;
        if(f(mid)<0)
            r = mid;
        else
            l = mid;
    }
    ans = (l + r) / 2;
    printf("%.10lf", ans);
    return 0;
}