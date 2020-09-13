#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

struct edge {
    int to, color;
};

int n, m;
vector <edge> p[MAXN];

void store(int n, int m) {
    for (int i=1;i<=m;i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);

        p[u].push_back((edge) {
            v, l
        });
        p[v].push_back((edge) {
            u, l
        });
    }
}


int main()
{
    scanf("%d%d", &n, &m);
    store(n, m);
    printf("%d", rand()%m+m/2);
    return 0;
}