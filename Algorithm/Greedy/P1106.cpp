#include <cstdio>
#include <cstring>

/*
struct Node{
    int data;
    Node *pre, *next;
} *head;

int temp;

void build(){               //*建立链表
    head = new Node;
    Node *tail = head;
    scanf("%d", &temp);
    while(temp!=-1){
        Node *p = new Node;
        p->data = temp;
        p->next = NULL;
        p->pre = head;
        tail->next = p;
        tail = p;
        scanf("%d", &temp);
    }
}

void print(){               //*输出链表中的数据
    Node *p = head->next;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void get_data(int i){       //*输出第i个节点的值
    int k = 1;
    Node *p = head->next;
    while(p!=NULL&&k<i){
        p = p->next;
        k++;
    }
    if(p==NULL)
        printf("Not Found!");
    else
        printf("%d", p->data);
}

void insert(int x,int i){   //*在第i个节点前插入x
    int k = 0;
    Node *p = head;
    while(p!=NULL&&k<i-1){  //*寻找第i-1个节点
        p = p->next;
        k++;
    }
    if(p==NULL)
        printf("Not Found!");
    else{
        Node *t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void del(int i){         //*删除第i个节点
    int k = 0;
    Node *p = head;
    while(p->next!=NULL&&k<i-1){
        p = p->next;
        k++;
    }
    if(p->next==NULL)
        printf("Not Found!");
    else{
        Node *t = p->next;
        p->next = p->next->next;
        delete t;
    }
}

int get_len(){          //*计算链表的长度
    int k = 0;
    Node *p = head;
    while(p->next!=NULL){
        k++;
        p = p->next;
    }
    return k;
}*/
int a[255], k, len;
bool check;

void read(){
    char s[255];
    scanf("%s", s);
    len = strlen(s);
    for (int i = 1; i <= len;i++)
        a[i] = s[i - 1] - '0';
}

int main()
{
    /*build();
    printf("%d\n", get_len());
    print();
    del(2);
    print();
    insert(543, 3);
    print();*/

    read();
    scanf("%d", &k);
    if(k==len){
        printf("0");
        return 0;
    }
    while(k){
        int i = 1;
        for (; i <= len;i++){
            if ((a[i] > a[i + 1]&&i!=len)||(i==len&&a[i]>=a[i-1])){
                k--;
                if(i==len)
                    a[i] = 0;
                else if(i!=len)
                    for (int j = i; j <= len;j++)
                        a[j] = a[j + 1];
                len--;
                break;
            }
        }
    }
    int m = 1;
    for (int i = 1; (!a[i]&&i < len); i++)
        m++;
    for (int i = m; i <= len; i++)
        printf("%d", a[i]);
    return 0;
}