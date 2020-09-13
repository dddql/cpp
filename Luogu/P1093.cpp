#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
    int num;
    int chinese;
    int math;
    int english;
    int total;
};
student stu[301];
int n;
int index[301];

void input() {
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &stu[i].chinese, &stu[i].math, &stu[i].english);
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
        stu[i].num = i;
    }
}

//*STL
bool cmp(student a, student b) {
    if (a.total>b.total)
        return true;
    else if(a.total==b.total){
        if(a.chinese>b.chinese)
            return true;
        else if(a.chinese==b.chinese){
            if(a.num<b.num)
                return true;
        }
    }
    return false;
}

//*传统
/*void bubble_sort() {
    bool if_swap;
    for (int i = 2; i <= 6;i++)
    {
        if_swap = false;
        for (int j = n; j >= i;j--)
        {
            if(stu[index[j]].total>stu[index[j-1]].total)
                swap(index[j], index[j - 1]);
                
            else if(stu[index[j]].total==stu[index[j-1]].total)
            {
                if(stu[index[j]].chinese>stu[index[j-1]].chinese)
                    swap(index[j], index[j - 1]);
            }
        }
        if (if_swap==false)
            break;
    }
}
*/

void output() {
    for (int i = 1; i <= n;i++)
        printf("%d %d\n", stu[index[i]].num, stu[index[i]].total);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 5;i++)
        index[i] = i;

    input();
    //freopen("P1093_8.in", "r", stdin);

    sort(stu + 1, stu + n + 1, cmp);
    //bubble_sort();

    output();
    return 0;
}