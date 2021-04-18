#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1000;

struct node{
    char data;
    node *ls, *rs;
} c[maxn << 2];
node *p = c;

int i = 0;
char s[1000];

void build(node *&t){
    if(s[i]!='.'){
        t = ++p;
        t->data = s[i++];
        build(t->ls);
        build(t->rs);
    }
    else{
        i++;
        t = NULL;
    }
}

void ask_pre(node *&t){
    if(t==NULL)
        return;
    printf("%c", t->data);
    ask_pre(t->ls);
    ask_pre(t->rs);
}

void ask_mid(node *&t){
    if(t==NULL)
        return;
    ask_mid(t->ls);
    printf("%c", t->data);
    ask_mid(t->rs);
}

void ask_sub(node *&t){
    if(t==NULL)
        return;
    ask_sub(t->ls);
    ask_sub(t->rs);
    printf("%c", t->data);
}

int main()
{
    node *t = NULL;
    scanf("%s", s);
    build(t);
    ask_pre(t);
    printf("\n");
    ask_mid(t);
    printf("\n");
    ask_sub(t);
    return 0;
}