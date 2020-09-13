#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string work()
{
    char c;
    string ans;

    //*真的很无语，不知道为什么不加“==1”第九个点就会超时超内存
    while (scanf("%c", &c) == 1)
    {

        if (c == '\n')
            break;

        if (c == '[')
        {
            int d;
            scanf("%d", &d);
            string s = work();
            while (d--)
                ans += s;
        }

        else if (c == ']')
            break;

        else
            ans += c;
    }
    return ans;
}
int main()
{
    //*printf为C语言中函数，而C语言中无string类型，需调用c_str()转换
    //?printf("%s", work().c_str());
    //*或者直接使用cout输出
    cout << work();
    return 0;
}