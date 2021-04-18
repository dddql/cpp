#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

const int maxn = 3e5+10;
const int max_n = 1e3 + 10;
const int max_w = 22;
const int maxa = 26;

int n, m;
char word[max_w], tmp[max_w];

struct trie{
    int node[maxn][maxa], cnt;
    bitset<1000> exist[maxn];

    void insert(char *s, int x){
        int p = 0;
        for (int i = 1; s[i];i++){
            int c = s[i] - 'a';
            if(!node[p][c])
                node[p][c] = ++cnt;
            p = node[p][c];
        }
        exist[p][x] = 1;
    }

    void find(char *s){
        int p = 0;
        for (int i = 1; s[i];i++){
            int c = s[i] - 'a';
            if(!node[p][c]){
                printf("\n");
                return;
            }
            p = node[p][c];
        }
        for (int i = 1; i <= n;i++)
            if(exist[p][i])
                printf("%d ", i);
        printf("\n");
    }
} trie;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        int num = 0;
        scanf("%d", &num);
        for (int j = 1; j <= num;j++){
            scanf("%s", word + 1);
            trie.insert(word,i);
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m;i++){
        scanf("%s", tmp + 1);
        trie.find(tmp);
    }
    return 0;
}