#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<char> ans;

int q;

void encode(int &l,char pre[]){
    for (; l >= 1;l--){
        if (pre[l] != '0')
            ans.push_back((char)((char)96 + (int)(pre[l] - '0')));
        else if(pre[l]=='0'){
            int flag = (int)(pre[l-1]-'0') + (int)(pre[l-2]-'0') * 10;
            ans.push_back(((char)96 + (char)flag));
            l-=2;
        }
    }
}

int main(){
    scanf("%d", &q);
    for (int i = 1; i <= q;i++){
        int n;
        scanf("%d", &n);
        getchar();
        char pre[n + 1];
        for (int i = 1; i <= n;i++)
            scanf("%c", &pre[i]);
        encode(n,pre);

        for (int i = ans.size()-1; i >= 0;i--)
            printf("%c", ans[i]);
        printf("\n");

        memset(pre, '0', sizeof(pre));
        ans.clear();
    }
    return 0;
}