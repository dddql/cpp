//*基本排序模板
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int maxn = 7;

int a[maxn], temp[maxn];

void bubble_sort(int data[],int len){
    bool if_swap;
    for (int i = 1; i < len;i++){
        if_swap = false;
        for (int j = 1; j <= len - i;j++){
            if(data[j]>data[j+1])
                swap(data[j], data[j + 1]);
            if_swap = true;
        }
        if(if_swap==false)
            break;
    }
}

void select_sort(int data[],int len){
    int k;
    for (int i = 1; i < len;i++){
        k = i;
        for (int j = i; j <= len;j++){
            if(data[j]<data[k])
                k = j;
        }
        if(k!=i)
            swap(data[i], data[k]);
    }
}

void insertion_sort(int data[],int len){
    for (int i = 2; i <= len;i++){
        int key = data[i];              //*“提取”当前值
        int j = i - 1;
        while (j >= 1&&data[j]>key){
            data[j + 1] = data[j];      //*移位操作
            j--;
        }
        data[j + 1] = key;
    }
}

void merge_sort(int l,int r,int data[],int temp[]){
    if(l==r)                        //*所有越界判断放在最前面
        return;

    int mid = (l + r) >> 1;

    merge_sort(l, mid, data, temp);
    merge_sort(mid + 1, r, data, temp);

    int p = l, q = mid + 1, i = l;

    while(p<=mid&&q<=r){
        if(data[p]<data[q])
            temp[i++] = data[p++];
        else
            temp[i++] = data[q++];
    }

    while(p<=mid)
        temp[i++] = data[p++];
    while(q<=r)
        temp[i++] = data[q++];

    for (int i = l; i <= r;i++)
        data[i] = temp[i];
}

int getrand(int l = 0,int r = 0){
        srand(time(0));
        return rand() % (r - l + 1) + l;
    }

void quick_sort(int l,int r,int data[]){
    if(l>=r)                //*防止之后产生随机数时出现负数
        return;             //*所有越界判断放在最前面

    int p = l, q = r;
    int t = getrand(l, r);  //*使用随机值，防止被卡

    while(p<q){
        while(data[p]<t&&p<q)
            p++;
        while(data[q]>t&&p<q)
            q--;
        if(p<q)
            swap(data[p],data[q]);
    }

    if(p==q)
        swap(data[p], data[t]);

    quick_sort(l, p - 1, data);
    quick_sort(q + 1, r, data);
}

int main(){
    int len;
    scanf("%d", &len);
    for (int i = 1; i <= len;i++)
        scanf("%d", &a[i]);

    quick_sort(1, len, a);

    for (int i = 1; i <= len;i++)
        printf("%d ", a[i]);
    return 0;
}