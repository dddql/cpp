#include <iostream>
#include <string>
using namespace std;
void ask_back(string mid,string pre){
    if(mid.size()){
        char c = pre[0];
        int x = mid.find(c);
        ask_back(mid.substr(0, x), pre.substr(1, x));
        ask_back(mid.substr(x + 1), pre.substr(x+1));
        cout << c;
    }
}
int main(){
    string mid, pre;
    cin >> mid >> pre;
    ask_back(mid, pre);
    return 0;
}