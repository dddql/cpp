#include <cstdio>
#include <cmath>

int L;
int sum,cnt;

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
    scanf("%d", &L);
    for(int i=1;;i++){ 
        if(is_prime(i)){ 
            sum+=i;
            if(sum<=L){ 
                cnt++;
                printf("%d\n", i);
            }
            else{ 
                printf("%d", cnt);
                return 0;
            }
        }
    }
    return 0;
}