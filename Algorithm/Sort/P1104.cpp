#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
struct student{
    string name;
    int y, m, d;
    int num;
} stu[105];

bool cmp(student a,student b){
    if(a.y!=b.y)
        return a.y < b.y;
    if(a.m!=b.m)
        return a.m < b.m;
    if(a.d!=b.d)
        return a.d < b.d;
    else
        return a.num > b.num;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        cin>>stu[i].name>>stu[i].y>>stu[i].m>>stu[i].d;
        stu[i].num = i;
    }
    stable_sort(stu + 1, stu + n + 1, cmp);
    for (int i = 1; i <= n;i++)
        cout<<stu[i].name<<endl;
    return 0;
}