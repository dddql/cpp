#include <bits/stdc++.h>
using namespace std;

vector<int> q;
int mp[305][305],rslt[305][305],mark[1005],sfzone[305][305],m,x,y,a,b,tmp=0,mthd[5][3] = {{1,0},{0,1},{-1,0},{0,-1}};

struct star{
    int sx,sy,st;
    void hit(){
        mp[sx][sy] = 1;
        for(int i = 0;i < 4;i++){
            int a = sx + mthd[i][0],b = sy + mthd[i][1];
            if(a >= 0&&b >= 0)
                mp[a][b] = 1;
        }
    }
    void hits(){
        sfzone[sx][sy] = 1;
    	for(int i = 0;i < 4;i++){
            int a = sx + mthd[i][0],b = sy + mthd[i][1];
            if(a >= 0&&b >= 0)
                sfzone[a][b] = 1;
        }
    }
    void scan(){
        scanf("%d%d%d",&sx,&sy,&st);
    }
}s[50005];

bool cmp(star a,star b){
	return a.st<b.st;
}

int main(){
    scanf("%d",&m);
    memset(mp,0,sizeof(mp));
    memset(sfzone,0,sizeof(sfzone));
    memset(rslt,-1,sizeof(rslt));
    memset(mark,0,sizeof(mark));
    mark[0] = rslt[0][0] = 0;
    mp[0][0] = 1;
    q.push_back(0);
    for(int i = 0;i < m;i++){
        s[i].scan();
        s[i].hits();
        if(s[i].st == 0){
            s[i].hit();
        }
    }
    sort(s,s+m,cmp);
    for(int i = 0;i < m;i++){
		mark[s[i].st+1]++;
    }
    for(int i = 1;i <= s[m-1].st;i++){
    		mark[i] += mark[i-1];
    }
    while(!q.empty()){
    	x = q[0]/1000;
    	y = q[0]%1000;
    	q.erase(q.begin());
        if(tmp != rslt[x][y]+1)
    		for(int i = mark[tmp+1];i < mark[tmp+2];i++)
    			s[i].hit();
    	tmp = rslt[x][y]+1;
        //cout << x <<" "<< y <<" "<< tmp - 1 << endl;
        for(int i = 0;i < 4;i++){
    		a = x + mthd[i][0];
    		b = y + mthd[i][1];
			if(a >= 0&&b >= 0&&mp[a][b] == 0){
				if(sfzone[a][b] == 0){
					cout<< (rslt[x][y]+1) <<endl;
					return 0;
				}
				rslt[a][b] = rslt[x][y]+1;
                mp[a][b] = 1;
                q.push_back(a*1000+b);
			}
    	}
    }
    cout<< -1 <<endl;
    return 0;
}