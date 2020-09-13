#include <cstdio>
#include <cmath>

int n, ans;

void work(int index,int T) {
    if(T==1)
        ans++;
    else{
        for (int i = index; i <= T; i++){
            if (T % i == 0) //*需为%
                work(i, T / i);
        }
    }
}

int main()
{
    scanf("%d", &n);
    work(2,n);
    printf("%d", ans);
    return 0;
}