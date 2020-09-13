#include <bits/stdc++.h>

const int MAXN = 1e3 + 1;
int a[MAXN];

using namespace std;

int search(int a[], int l, int r, int m)
{
    int mid = (l + r) / 2;
    if (l > r)
        return -1;
    if (m == a[mid])
        return mid;
    if (m > a[mid])
    {
        l = mid + 1;
        search(a, l, r, m);
    }
    else
    {
        r = mid - 1;
        search(a, l, r, m);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cin >> n;
    int k = search(a, 0, m - 1, n);
    if (k == -1)
        cout << "no";
    else
        cout << k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}