#include <cstdio>

struct Node{
    int data;
    Node *ls, *rs;

    void insert(int x){
        Node n = new Node;
        n->data = x;
        n->ls = n->rs = NULL;
    }
};



int main()
{
    
    return 0;
}