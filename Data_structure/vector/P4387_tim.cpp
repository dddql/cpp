#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> en;
vector<int> ot;

int main(){
    int n,m,tmp,flag = 1;
    cin >> n;
    for (int i = 0; i < n;i++){
        flag = 1;
        cin >> m;
        for (int j = 0; j < m;j++){
            cin >> tmp;
            en.push_back(tmp);
        }
        for (int j = 0; j < m;j++){
            cin >> tmp;
            ot.push_back(tmp);
        }
        for (int j = 0; j < m;j++){
            if(en[j] == ot[0]){
                en.erase(find(en.begin(),en.end(),en[j]));
                ot.erase(ot.begin());
                j -= 2;
                m--;
            }
        }
        cout << ((en.empty()&&flag) ? "Yes" : "No")<< endl;
    }
        return 0;
}