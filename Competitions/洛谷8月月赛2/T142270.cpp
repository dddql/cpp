#include <cstdio>
#include <cmath>

long long a, b, c;
bool A[1000001], B[1000001];

int main()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    if(a<b){
        if(b-a<c){
            c -= b - a;
            a += b - a;
        }
        else{
            a += c;
            c = 0;
        }
    }
    else if(a>b){
        if(a-b<c){
            c -= a-b;
            b += a-b;
        }
        else{
            b += c;
            c = 0;
        }
    }
    if(a==b) {
        a += c / 2;
        b += c / 2;
        c -= 2 * (c / 2);
    }
    for (int i = 1; a>=i; i++){
        a -= i;
        A[i] = true;
    }
    for (int i = 1; b>=i; i++){
        b -= i;
        B[i] = true;
    }
    for (int i = 1;;i++){
        if(A[i]&&B[i])
            continue;
        else if((A[i]||B[i])||(A[i]==false&&B[i]==false)){
            printf("%d", i-1);
            break;
        }
    }
    return 0;
}