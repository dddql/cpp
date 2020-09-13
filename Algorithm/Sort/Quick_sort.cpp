#include <cstdio>
#include <cstdlib>
#include <ctime>

int a[11];
int n;

int getrand(int l, int r) {
    srand(time(0));
    return rand() % (r - l + 1) + l;
}

void Quick_sort(int l,int r){
    int start = l, end = r;
    int t = a[l].time;

    if(l>=r)
        return;

    while(start<end)
    {
        while(a[end].time>=t&&start<end)
            end--;
        if(start<end){
            a[start] = a[end];
            start++;
        }

        while(a[start].time<t&&start<end)
            start++;
        if(start<end){
            a[end] = a[start];
            end--;
        }
    }
    a[start].time = t;
    Quick_sort(l,start-1);
    Quick_sort(end+1, r);
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    Quick_sort(1, n);

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}