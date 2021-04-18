#include <bits/stdc++.h>
#define l(a) for(int i = 0; i < a;i++)
using namespace std;

//queue<int> q;
int mp[6][6], ans = 0,n, m, t, sx, sy, fx, fy, tx, ty, mthd[5][3] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int x,int y){
    if (x == fx&&y == fy){
        ans++;
        return;
    }
    if(x <= 0||y <= 0||x > n||y > m){
        return;
    }

    l(4){
        int a = x + mthd[i][0],b = y + mthd[i][1];
        if(mp[a][b] == 0){
            mp[a][b] = 1;
            dfs(a, b);
            mp[a][b] = 0;
        }
    }
}


int main(){
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    l(t){
        cin >> tx >> ty;
        mp[tx][ty] = 1;
    }
    mp[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}