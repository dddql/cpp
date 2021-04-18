//*给定中序，后序，求先序
#include <iostream>
#include <string>
using namespace std;

void ask_pre(string mid,string aft){
    if(mid.size()){
        char c = aft[aft.size() - 1];
        cout << c;
        int x = mid.find(c);    //*找到字符c的位置（下标）

        ask_pre(mid.substr(0, x), aft.substr(0, x));    //*从0位置开始，向后找x个字符，实际上不包括‘c’
        ask_pre(mid.substr(x + 1), aft.substr(x, aft.size() - x - 1));//*从x+1位置开始，一直到末尾
    }
}

int main(){
    string mid, aft;

    cin >> mid >> aft;

    ask_pre(mid, aft);

    return 0;
}