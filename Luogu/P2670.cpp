#include <cstdio>

char a[102][102];
int n, m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void output()
{
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
                printf("*");
            else
            {
                int sum = 0;
                for (int p = 0; p < 8; p++)
                    if (a[i + dx[p]][j + dy[p]] == '*')
                        sum++;
                printf("%d", sum);
            }
        }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);
    output();
    return 0;
}