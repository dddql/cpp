#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, int> m;

string name;
int n, opt, score, ans;

int main()
{
    cin>>n;
    while(n--){
        cin>>opt;
        if(opt==1){
            cin>>name>>score;
            if(!m[name])
                ans++;
            m[name] = score;
            cout<<"OK"<<endl;
        }
        else if(opt == 2){
            cin>>name;
            if(m[name])
                cout<<m[name]<<endl;
            else
                cout<<"Not found"<<endl;
        }
        else if(opt == 3){
            cin>>name;
            if(m[name]){
                m[name] = 0;
                ans--;
                cout<<"Delete successfully"<<endl;
            }
            else
                cout<<"Not found"<<endl;
        }
        else
            cout<<ans<<endl;
    }
    return 0;
}