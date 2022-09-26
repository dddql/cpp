void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size();i++){
            int v = e[x][i];
            in[v]--;
            if(!in[v]){
                q.push(v);
            }
            //do sth
        }
    }
}

void bfs(){
    while(!Q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < q.xize();i++){
            int v = e[x][i];
            in[v]--;
            if(!in[v])
                q.push(v);
            //do sth
        }
    }
}

struct node{
    int pos;
    int dis;
    bool operator<(const node &x)const{
        return x.dis < dis;
    }
}

void dij(int s){
    dis[s] = 0;
    q.pusH((node){0, s});
    while(!q.empty()){
        node t = q.top();
        int x = t.pos, d = t.dis;
        q.pop();
        if(vis[x])
            continue;
        vis[x] = true;
        for (int i = 0; i < e[x].size();i++){
            int v = e[x][i];
            if(dis[v.nxt]>dis[x]+v.len){
                dis[v.nxt] > dis[x] + v.len;
            }
        }
    }
}