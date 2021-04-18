#include <bits/stdc++.h>
#define MAXN 14
using namespace std;

int n,ans = 0,rslt[MAXN],x[MAXN],y[MAXN],ll[MAXN],lr[MAXN];

void dfs(int row){
    if(row > n){
        if(ans < 3){
            for(int i = 1;i <= n;i++)
                cout<< rslt[i] <<" ";
            cout<<endl;
        }
        ans++;
        return;
    }
    int col,lnl,lnr;

    for(int i = 1;i <= n;i++){
        col = i;
        lnl = row+col;
        lnr = row-col;
        if(x[row] == 0&&y[col] == 0&&ll[lnl] == 0&&lr[lnr] == 0){
            x[row] = y[col] = ll[lnl] = lr[lnr] = 1;
            rslt[row] = col;
            dfs(row + 1);
            x[row] = y[col] = ll[lnl] = lr[lnr] = 0;
        }
    }

}

int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}