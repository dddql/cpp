#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define random(a,b) (rand()%((b)-(a)+1)+(a))

int n;

int main()
{
    srand(time(0));
    n = random(1, 5000);
    printf("%d\n", n);
    return 0;
}