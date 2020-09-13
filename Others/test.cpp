#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    cout << "你";
    Sleep(1000);  /* VC 使用Sleep*/
    cout << "好"; /*输出“你”和“好”之间会间隔一千毫秒，即间隔一秒，Sleep()的单位为毫秒*/
    return 0;
}