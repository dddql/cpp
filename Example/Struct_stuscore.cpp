#include <bits/stdc++.h>
using namespace std;

struct student
{
    char name[25];
    int chinese;
    int math;
    int total;
};
student stu[110];

int index[110];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d", stu[i].name, &stu[i].chinese, &stu[i].math);
        stu[i].total = stu[i].chinese + stu[i].math;
    }
    for (int i = 0; i < n; i++)
        index[i] = i;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (stu[index[j]].total < stu[index[j + 1]].total)
                swap(index[j], index[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d\n", stu[index[i]].name, stu[index[i]].chinese, stu[index[i]].math, stu[index[i]].total);
    }
    return 0;
}