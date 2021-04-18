#include<bits/stdc++.h>
#define MAXN 35
using namespace std;

queue<int> q;
int n,a[MAXN][MAXN],m[MAXN*MAXN][2],tx,ty,p = 0,sx,sy,mthd[5][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> a[i][j];
            if ((i == 1 || i == n||j == 1||j == n)&&a[i][j] == 0){
                m[p][0] = i;
                m[p++][1] = j;
            }
        }
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            
        }
    }

    for (int i = 0; i < p;i++){
        sx = m[i][0];
        sy = m[i][i];
        // if(a[sx][sy] == -1)
        //     continue;
        cout << sx << " " << sy << endl;
        q.push(sx * 100 + sy);
        a[sx][sy] = -1;

        while(!q.empty()){
            sx = q.front() / 100;
            sy = q.front() % 100;
            q.pop();
            for (int i = 0; i < 4;i++){
                tx = sx + mthd[i][0];
                ty = sy + mthd[i][1];
                if ((tx > 0 && tx <= n && ty > 0 && ty <= n) && a[tx][ty] == 0){
                    a[tx][ty] = -1;
                    q.push(tx * 100 + ty);
                }
            }
        }
    }


    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            switch (a[i][j]){
            case -1:
                cout << 0 << " ";
                break;
            case 0:
                cout << 2 << " ";
                break;
            default:
                cout << 1 << " ";
                break;
            }
        }
        cout << endl;
    }
    return 0;
}