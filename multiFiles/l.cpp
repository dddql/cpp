#include "list.h"

int main(){
    //LNode *s = new LNode;
    LNode *s;
    InitList(s);
    print(s);
    for (int i = 1; i <= 5;i++)
        insert(s,i);
    print(s);
    return 0;
}