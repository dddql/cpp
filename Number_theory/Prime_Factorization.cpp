#include <cstdio>
#include <vector>
using namespace std;

vector<int> ret;
vector<int> factor(int x)
{
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0)
        {
            ret.push_back(i);
            x /= i;
        }
    if (x > 1)
        ret.push_back(x);
    return ret;
}

int n;

int main()
{
    scanf("%d", &n);
    factor(n);
    for (int i = 0; i < ret.size(); i++)
        printf("%d ", ret[i]);
    return 0;
}