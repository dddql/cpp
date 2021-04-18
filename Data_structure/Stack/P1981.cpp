#include <cstdio>
#include <cctype>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 100000;
const int mod = 10000;

struct stack_num{
    ll a[maxn], t = 0;
    void push(ll x){
        a[++t] = x;
    }
    void pop(){
        t--;
    }
    ll top(){
        return a[t];
    }
    ll size(){
        return t;
    }
    bool empty(){
        return t == 0;
    }
};
struct stack_op{
    char a[maxn];
    ll t = 0;
    void push(char c){
        a[++t] = c;
    }
    void pop(){
        t--;
    }
    char top(){
        return a[t];
    }
    ll size(){
        return t;
    }
    bool empty(){
        return t == 0;
    }
};


string p;
ll i = 0;

stack_num num;
stack_op op;

ll prior[256];

bool cmp_op(char x,char y){
    return prior[x] > prior[y];
}

ll calc(ll a,char op,ll b){
    switch(op){
        case '+':
            return (a + b)%mod;
        case '*':
            return (a * b)%mod;
    }
}

ll init(){
    ll s = 0;
    while(isdigit(p[i]))
        s = s * 10 + (p[i++] - '0');
    i--;
    return s;
}

int main(){
    //freopen("P1981_2.in", "r", stdin);

    prior['*'] = 2;
    prior['+'] = 1;

    cin>>p;

    while(p[i]!='\0'){
        if(isdigit(p[i]))
            num.push(init());
        else{
            while(!op.empty()&&cmp_op(op.top(),p[i])){
                char o = op.top();
                op.pop();
                ll y = num.top() % mod;
                num.pop();
                ll x = num.top() % mod;
                num.pop();
                ll result = calc(x, o, y) % mod;
                num.push(result % mod);
            }
            op.push(p[i]);
        }
        i++;
    }

    while(!op.empty()){
        char o = op.top();
        op.pop();
        ll y = num.top() % mod;
        num.pop();
        ll x = num.top() % mod;
        num.pop();
        ll result = calc(x, o, y) % mod;
        num.push(result % mod);
    }

    printf("%lld", num.top() % mod);
    return 0;
}