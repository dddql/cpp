/*
f[i][j]表示前i根筷子凑成j双筷子的长度最小差平方和
若不取用第i根筷子：
    f[i][j] = f[i-1][j];
若取用：
    f[i][j] = f[i-2][j-1];
    
注意根据题目实际意义确定循环范围：
    2<=i<=m, 1<=j<=i/2
*/

#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    
    return 0;
}