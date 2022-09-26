#include "list.h"

void InitList(LNode *&L){
    L = new LNode;
    L->next = NULL;
}

void insert(LNode *&L, ElemType e){
    LNode *p, *r;
    p = new LNode;
    p->data = e;
    p->next = NULL;
    if(L->next==NULL){
        L->next = p;
        r = p;
    }
    else{
        r->next = p;
        r = p;
    }
}

void print(LNode *&L){
    LNode *p;
    p = L->next;
    while(p){
        printf("%d", p->data);
        p = p->next;
    }
}