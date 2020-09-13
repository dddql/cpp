#include <cstdio>
#include <cmath>

int a, b;
int t;

bool digit(int n) {
    if(1000<=n&&n<=9999||100000<=n&&n<=999999||10000000<=n&&n<=99999999)
        return false;
}
bool is_palindromes(int n) 
{
    int temp = n, num = 0;
    while(temp)
    {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    if(num==n)
        return true;
    else
        return false;
}

bool is_prime(int n)
{
	if(n<2) return false;
	if(n==2||n==3) return true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
    scanf("%d%d", &a, &b);
    if(a%2==0)
        a++;
    for (int i = a; i <= b;i+=2)
    {
        if(digit(i)&&is_palindromes(i)&&is_prime(i))
            printf("%d\n", i);
    }
    return 0;
}