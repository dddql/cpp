#include <cstdio>
#include <vector>
using namespace std;

int n, q, opt;
int i, j, k;
int main(){
    scanf("%d%d", &n, &q);
    vector< vector<int> > locker(n+1);
    while(q--){
        scanf("%d", &opt);
        if(opt==1){
            scanf("%d%d%d", &i, &j, &k);
            if(locker[i].size()<j+1)
                locker[i].resize(j + 1);
            locker[i][j] = k;
        }
        else{
            scanf("%d%d", &i, &j);
            printf("%d\n", locker[i][j]);
        }
    }
    return 0;
}