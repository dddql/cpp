#include <cstdio>
using namespace std;

const int maxn = 5e5+10;
const int maxa = 26;

struct trie{
    int node[maxn][maxa], cnt;
    int exist[maxn];

    void insert(char *s){
        int p = 0;
        for (int i = 1; s[i];i++){
            int c = s[i] - 'a';
            if(!node[p][c])
                node[p][c] = ++cnt;
            p = node[p][c];
        }
        exist[p] = 1;
    }

    int find(char *s){
        int p = 0;
        for (int i = 1; s[i];i++){
            int c = s[i] - 'a';
            if(!node[p][c])
                return 0;
            p = node[p][c];
        }
        return exist[p]++;
    }
} trie;

int n, m;

int main()
{
    //freopen("P2580_1.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        char s[52];
        scanf("%s", s + 1);
        trie.insert(s + 1);
    }
    scanf("%d",&m);
    for (int i = 1; i <= m; i++){
        char s[52];
        scanf("%s", s + 1);
        int rslt = trie.find(s + 1);
        if(rslt==1)
            printf("OK\n");
        else if(rslt>1)
            printf("REPEAT\n");
        else
            printf("WRONG\n");
    }
    return 0;
}