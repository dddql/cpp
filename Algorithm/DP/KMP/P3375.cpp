//*KMP字符串匹配
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string txt;
string pat;

/*
struct KMP{
    int dp[105][256];
    //string pat;

    KMP(string pat){
        //this->pat = pat;
        int M = pat.length();

        dp[0][pat[0]] = 1;

        int X = 0;
        int j = 1;
        for (; j < M;j++){
            for (int c = 0; c < 256;c++){
                if(pat[j]==c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
        }

        X = dp[X][pat[j]];
    }

    int search(string txt){
        int N = txt.length();
        int M = pat.length();

        int j = 0;
        for (int i = 0; i < N;i++){
            j = dp[j][txt[0]];

            if(j==M)
                return i - M + 1;
        }

        return -1;
    }
} s;
*/
int dp[105][256];
    //string pat;

void init(string &p){
    //this->pat = pat;
    int M = p.size();

    dp[0][p[0]] = 1;

    int X = 0;
    for (int j = 1; j < M; j++){
        for (int c = 0; c < 256;c++){
            if(p[j]==c)
                dp[j][c] = j + 1;
            else
                dp[j][c] = dp[X][c];
        }
        X = dp[X][p[j]];
    }
}

int search(string &txt,string &pat){
    int N = txt.length();
    int M = pat.length();

    int j = 0;
    for (int i = 0; i < N;i++){
        j = dp[j][txt[i]];
        if(j==M)
            return i - M + 1;
    }
    return -1;
}

int main()
{
    cin >> txt;
    cin >> pat;

    init(pat);
    printf("%d", search(txt, pat));

    return 0;
}