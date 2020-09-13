#include <bits/stdc++.h>
using namespace std;
int main()
{
    float m, h;
    cin >> m >> h;
    float BMI = m / pow(h, 2);
    if (BMI < 18.5)
        cout << "Underweight";
    else if (BMI >= 18.5 && BMI < 24)
        cout << "Normal";
    else
        cout << BMI << endl
             << "Overweight";
    return 0;
}