#include <cstdio>
#include <cmath>

const int M = 12345;
int n;
int odd[1001], even[1001];

int cal(int n) {
    odd[1] = 1;
    odd[2] = 17;

    even[1] = 9;
    even[2] = 73;

    for (int i = 2; i < n;i++){
        even[i + 1] = (even[i]%M * even[1])%M + (odd[i]%M * odd[1])%M;
        odd[i + 1] = 
    }
    return even[n]%M;
}
int main()
{
    scanf("%d", &n);
    printf("%d", cal(n));
    return 0;
}