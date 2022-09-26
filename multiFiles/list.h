#include <cstdio>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode;

void InitList(LNode *&L);

void insert(LNode *&L, ElemType e);

void print(LNode *&L);

