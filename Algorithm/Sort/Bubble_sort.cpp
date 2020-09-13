#include <bits/stdc++.h>
using namespace std;

//TODO 冒泡排序模板
void bubble_sort(int data[], int length)
{
	bool if_swap;
	for (int i = 0; i < length - 1; i++)
	{
		if_swap = false;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
			}
			if_swap = true;
		}
		if (if_swap == false)
			break;
	}
}

int main()
{
	int len;
	scanf("%d", &len);
	int a[len];
	for (int i = 0; i < len; i++)
		scanf("%d", &a[i]);
	bubble_sort(a, len);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	return 0;
}
