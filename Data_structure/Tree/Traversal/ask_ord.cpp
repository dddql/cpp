#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string mid, lay;


void ask_pre(string mid,string lay){
    if(mid.size()){
        char c = lay[0];
        int k = mid.find(c);
        vector<int> ls,rs;
        for (int i = 1; i < lay.size();i++){
            
        }
    }
}

int main()
{
    cin >> mid >> lay;
    ask_pre(mid, lay);
    return 0;
}