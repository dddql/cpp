#include <cstdio>


void floyd(){
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                //if(dis[i][j]>dis[i][k]+dis[k][j])
                dis[i][j] = dis[i][j]||(dis[i][k] && dis[k][j]);
}
int main()
{
    
    return 0;
}