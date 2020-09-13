#include <cstdio>
#include <vector>
using namespace std;
int n, m, tmp;
vector<int> stu;    //*下标默认从0开始
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++){
        scanf("%d", &tmp);
        stu.push_back(tmp);
    }
    for (int i = 1; i <= m;i++){
        scanf("%d", &tmp);
        printf("%d\n", stu[tmp-1]);
    }
    return 0;
}