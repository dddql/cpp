#include <cstdio>

int A = 85, B = 51;
int p, q, r, s, u, v;

int main()
{
    p = A & B;
    q = A | B;
    r = A ^ B;
    s = ~A;
    u = A << 2;
    v = A >> 3;

    printf("%d %d %d %d %d %d", p, q, r, s, u, v);

    return 0;
}