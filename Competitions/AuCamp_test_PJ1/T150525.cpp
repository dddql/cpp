#include <cstdio>

long long A, N;
float K, C;

int main(){
    scanf("%lld%lld%f", &A, &N, &K);

    if(K==1)
        K = A * 0.05;
    else if(K==2)
        K = A * 0.03;
    else if(K==3)
        K = A * 0.01;
    else
        K = 0;

    N = N > 25 ? 25 : N;

    C = A * 1.0 / N + K;

    printf("%.2f", C);
    return 0;
}