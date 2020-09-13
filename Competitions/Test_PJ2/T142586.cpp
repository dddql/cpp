#include <cstdio>
#include <algorithm>

using namespace std;

int n, i=0;
int a[5]={ 0 };
char car[50];

int main()
{
    scanf("%d", &n);
    scanf("%s", car);

    while (car[i]!='\0')
    {
        a[car[i]-'A'+1]++;
        i++;
    }
    sort(a, a+5);

    int ans=0;
    for (int i=1;i<5;i++) {
        if (a[i]>n/4)
            ans+=a[i]-n/4;
    }

    printf("%d", ans);
    return 0;
}