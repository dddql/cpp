#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    cout << "��";
    Sleep(1000);  /* VC ʹ��Sleep*/
    cout << "��"; /*������㡱�͡��á�֮�����һǧ���룬�����һ�룬Sleep()�ĵ�λΪ����*/
    return 0;
}