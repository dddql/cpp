#include <cstdio>
#include <vector>
using namespace std;

vector<int> factor(int x){
    vector<int> ret;
    for(int i=2;i*i<=x;i++)
        while(x%i==0){
            ret.push_back(i);
            x /= i;
        }
    if(x>1)
        ret.push_back(x);
    return ret;
}

int main()
{
    
    return 0;
}