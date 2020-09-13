#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main(){
    int x,a,y,b;
    cin>>x>>a>>y>>b;
    float m=(b*y-a*x)/(b-a);
    cout<<fixed<<setprecision(2)<<m<<endl;
    return 0;
}