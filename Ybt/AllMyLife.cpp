#include <bits/stdc++.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

//TODO 1001：Hello,World!
/*
int main()
{
	cout << "hello world" << endl;
	system("pause");
	return 0;
}
*/
//TODO 1002：输出第二个整数
/*
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << b << endl;
	return 0;
}
*/
//TODO 1003：对齐输出
/*
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << setw(8) << a << " " << setw(8) << b << " " << setw(8) << c << endl;
	return 0;
}
*/
//TODO 1004：字符三角形
/*
int main()
{
	int i = 1;
	char n;
	cin >> n;
	while (i <= 3)
	{
		int j = 1;
		while (j <= 3 - i)
		{
			cout << " ";
			j++;
		}
		j = 1;
		while (j <= 2 * i - 1)
		{
			cout << n;
			j++;
		}
		cout << endl;
		i++;
	}
	return 0;
}
*/
//TODO 1005：地球人口承载力估计
/*
int main()
{
	int x, a, y, b;
	cin >> x >> a >> y >> b;
	float m = (b * y - a * x);
	float c = b - a;
	cout << fixed << setprecision(2) << m / c << endl;
	return 0;
}
*/
//TODO 1006：A+B问题
/*
int main()
{
	long double a, b;
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}
*/
//TODO 1007：计算(a+b)×c的值
/*
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) * c << endl;
	return 0;
}
*/
//TODO 1008：计算(a+b)/c的值
/*
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) / c << endl;
	return 0;
}
*/
//TODO 1009：带余除法
/*
int main()
{
	int a, b;
	cin >> a >> b;
	cout << a / b << " " << a % b << endl;
	return 0;
}
*/
//TODO 1010：计算分数的浮点数值
/*
int main()
{
	float a, b;
	cin >> a >> b;
	cout << fixed << setprecision(9) << a / b << endl;
	return 0;
}
*/
//TODO 1011：甲流疫情死亡率
/*
int main()
{
	float a, b;
	cin >> a >> b;
	cout << fixed << setprecision(3) << (b / a) * 100 << '%' << endl;
	return 0;
}
*/
//TODO 1012：计算多项式的值
/*
int main()
{
	double x, a, b, c, d;
	cin >> x >> a >> b >> c >> d;
	cout << fixed << setprecision(7) << a * x * x * x + b * x * x + c * x + d << endl;
	return 0;
}
*/
//TODO 1023：Hello,World!的大小
/*
int main()
{
	printf("%d", sizeof("Hello, World!"));
	return 0;
}
*/
//TODO 1024：保留3位小数的浮点数
/*
int main()
{
	float a;
	scanf("%f", &a);
	printf("%.3f", a);
	return 0;
}
*/
//TODO 1025：保留12位小数的浮点数
/*
int main()
{
	double a;
	scanf("%lf", &a);
	printf("%.12lf", a);
	return 0;
}
*/
//TODO 1027：输出浮点数
/*
int main()
{
	double a;
	scanf("%lf", &a);
	printf("%f\n%-6.5f\n%e\n%g\n", a, a, a, a);
	return 0;
}
*/
//TODO 1036：A×B问题
/*
int main()
{
	long long a, b, c;
	cin >> a >> b;
	c = a * b;
	cout << c << endl;
	return 0;
}
*/
//TODO 1037：计算2的幂
/*
int main()
{
	int n;
	unsigned long long a;
	scanf("%d", &n);
	a = pow(2, n);
	printf("%llu", a);
	return 0;
}
*/
//TODO 1040：输出绝对值
/*
int main()
{
	float a;
	cin >> a;
	cout << abs(a) << endl;
	return 0;
}
*/
//TODO 1062：最高的分数
/*
int main()
{
	int n, score, maxs = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score;
		maxs = maxs < score ? score : maxs;
	}
	cout << maxs << endl;
	return 0;
}
*/
//TODO 1063：最大跨度值
/*
int main()
{
	int n, score, maxs = -1, mins = 151;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score;
		maxs = maxs < score ? score : maxs;
		mins = mins > score ? score : mins;
	}
	int a = maxs - mins;
	cout << a << endl;
	return 0;
}
*/
//TODO 1068：与指定数字相同的数的个数
/*
int main()
{
	int i, m, n, num, ans = 0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> num;
		if (num == n)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
*/
//TODO 1069：乘方计算
/*
int main()
{
	int a, n, i, ans = 1;
	cin >> a >> n;
	for (int i = 1; i <= n; i++)
	{
		ans *= a;
	}
	cout << ans << endl;
	return 0;
}
*/
//TODO 1073：救援
/*
int main()
{
	int n, p;
	double x, y, d, ans = 0;
	cin >> n;
	while (n--)
	{
		cin >> x >> y >> p;
		d = sqrt(x * x + y * y);
		ans += 2 * d / 50 + (1 + 0.5) * p;
	}
	cout << ceil(ans) << endl;
	return 0;
}
*/
//TODO 1074：津津的储蓄计划
/*
int main()
{
	int t = 0, n = 0, x, ans;
	for (int i = 1; i <= 12; i++)
	{
		cin >> x;
		t += 300 - x;
		if (t < 0)
		{
			cout << -i << endl;
			return 0;
		}
		if (t >= 100)
		{
			n += t / 100;
			t %= 100;
		}
	}
	ans = n * 120 + t;
	cout << ans << endl;
	return 0;
}
*/
//TODO 1075：药房管理
/*
int main()
{
	int a, b, c, no = 0;
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
	{
		cin >> c;
		if (c <= a)
			a -= c;
		else
			no++;
	}
	cout << no << endl;
	return 0;
}
*/
//TODO 1076：正常血压
/*
int main()
{
	int a, b, c, d = 0, max = 0;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		cin >> b >> c;
		if (b <= 140 && b >= 90 && c <= 90 && c >= 60)
			d++;
		else
		{
			max = max < d ? d : max;
			d = 0;
		}
	}
	cout << max << endl;
	return 0;
}
*/
//TODO 1086：角谷猜想
/*
1.
int main()
{
	int n;
	cin>>n;
	while(n!=1){
        if(n%2==0){
        	cout<<n<<'/'<<2<<'='<<n/2<<endl;
        	n/=2;
        }
        else{
        	cout<<n<<'*'<<3<<'+'<<1<<'='<<n*3+1<<endl;
        	n=n*3+1;
        }
	}
	system("pause");
	return 0;
}
*/
/*
2.
int main()
{
	int a;
	cin>>a;
	while(a-1){
		if(a%2==0){
		cout<<a<<'/'<<2<<'='<<a/2<<endl;
		a/=2;
		int b=a/2;
		if(b==1){
		cout<<a<<'/'<<2<<'='<<a/2<<endl;
		cout<<"End"<<endl;
		return 0;
		}
		
		}
		if(a%2==1){
		cout<<a<<'*'<<3<<'+'<<1<<'='<<a*3+1<<endl;
		a=a*3+1;
		}
	}
	return 0;
}
*/
//TODO 1087：级数求和
/*
int main()
{
	int n = 1, k;
	double Sn = 0;
	cin >> k;
	while (Sn <= k)
	{
		Sn += (1.0 / n);
		n++;
	}
	n--;
	cout << n << endl;
	return 0;
}
*/
// TODO 1088：分离整数的各个数
/*
int main()
{
	int n;
	cin >> n;
	while (n)
	{
		cout << n % 10 << " ";
		n /= 10;
	}
	return 0;
}
*/
//TODO 1090：含k个3的数
/*
int main()
{
	int m, k, i = 0;
	cin >> m >> k;
	if (m % 19 == 0)
	{
		while (m)
		{
			if ((int)m % 10 == 3)
			{
				i++;
			}
			m /= 10;
		}
		if (i == k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}
*/
//TODO 1094：与7无关的数
/*
int main()
{
	int n, s = 0;
	int i, t;
	bool b;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		t = i;
		b = 1;
		while (t)
		{
			if (t % 10 == 7 || t % 7 == 0)
			{
				b = 0;
				break;
			}
			else
				t /= 10;
		}
		if (b)
			s = s + i * i;
	}
	cout << s << endl;
	return 0;
}
*/
//TODO 1097：画矩形
/*
int main()
{
	int a, b, d;
	char e, c;
	int i, j;
	scanf("%d%d%s%d", &a, &b, &c, &d);
	if (d)
		e = c;
	else
		e = ' ';
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			if (j == 1 || j == b || i == 1 || i == a)
				printf("%c", c);
			else
				cout << e;
		}
		printf("\n");
	}
	return 0;
}
*/
//TODO 1098：质因数分解
/*
int main()
{
	int n, i;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		int m = n % i;
		if (m == 0)
			break;
	}
	cout << n / i << endl;
	return 0;
}
*/
//TODO 1100：金币
/*
int main()
{
	int n, i, j, d = 0, s = 0;
	cin >> n;
	for (i = 1;; i++)
	{
		for (j = 1; j <= i; j++)
		{
			d++;
			s = s + i;
			if (d == n)
			{
				cout << s << endl;
				return 0;
			}
		}
	}
	return 0;
}
*/
//TODO 1102：与指定数字相同的数的个数
/*
int main()
{
	int N, m, j = 0;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < N; i++)
	{
		if (a[i] == m)
			j++;
	}
	printf("%d", j);
	return 0;
}
*/
//TODO 1103：陶陶摘苹果
/*
int a[10];
int main()
{
	int c = 0, h;
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	scanf("%d", &h);
	for (int i = 0; i < 10; i++)
	{
		if (a[i] <= h + 30)
			c++;
	}
	printf("%d", c);
	return 0;
}
*/
//TODO 1104：计算书费
/*
int a[11];
int main()
{
	float c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
	for (int i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= 10; i++)
	{
		switch (i)
		{
		case 1:
			c1 = 28.9 * a[i];
			break;
		case 2:
			c2 = 32.7 * a[i];
			break;
		case 3:
			c3 = 45.6 * a[i];
			break;
		case 4:
			c4 = 78.0 * a[i];
			break;
		case 5:
			c5 = 35.0 * a[i];
			break;
		case 6:
			c6 = 86.2 * a[i];
			break;
		case 7:
			c7 = 27.8 * a[i];
			break;
		case 8:
			c8 = 43.0 * a[i];
			break;
		case 9:
			c9 = 56.0 * a[i];
			break;
		case 10:
			c10 = 65.0 * a[i];
			break;
		}
	}
	c = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9 + c10;
	printf("%.1f", c);
	return 0;
}
*/
//TODO 1105：数组逆序重存放
/*
int main()
{
	int N;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (int i = 0, j = (N - 1); i < j; i++, j--)
	{

		swap(a[i], a[j]);
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}
*/
//TODO 1106：年龄与疾病
/*
int main()
{
	int N;
	scanf("%d", &N);
	int n[N];
	float a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < N; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < N; i++)
	{
		int t = (n[i] >= 0) + (n[i] >= 19) + (n[i] >= 36) + (n[i] >= 61);
		switch (t)
		{
		case 1:
			a++;
			break;
		case 2:
			b++;
			break;
		case 3:
			c++;
			break;
		case 4:
			d++;
			break;
		default:
			break;
		}
	}
	printf("%.2f%%\n", a / N * 100);
	printf("%.2f%%\n", b / N * 100);
	printf("%.2f%%\n", c / N * 100);
	printf("%.2f%%\n", d / N * 100);
	return 0;
}
*/
//TODO 1107：校门外的树
/*
int main()
{
	int L, M, start, end, sum = 0;
	scanf("%d%d", &L, &M);
	int tree[L + 1];
	for (int i = 0; i <= L; i++)
		tree[i] = 1;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &start, &end);
		for (int j = start; j <= end; j++)
			tree[j] = 0;
	}
	for (int i = 0; i <= L; i++)
	{
		if (tree[i])
			sum++;
	}
	printf("%d", sum);
	return 0;
}
*/
//TODO 1108：向量点积计算
/*
int main()
{
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];
	printf("%d", ans);
	return 0;
}
*/
//TODO 1109：开关灯
/*
int a[MAXN];
int main()
{
	int p, l, first = 1;

	scanf("%d%d", &l, &p);
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			if (i % j == 0)
				a[i] = !a[i];
		}
	}
	for (int i = 1; i <= l; i++)
	{
		if (a[i])
		{
			if (first)
				first = 0;
			else
				printf(",");
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}
*/
//TODO 1110：查找特定的值
/*
int main()
{
	int n, f;
	scanf("%d", &n);
	int a[n];
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &f);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == f)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", -1);
	return 0;
}
*/
//TODO 1111：不高兴的津津
/*
int main()
{
	int a[8];
	int in, out;
	for (int i = 1; i <= 7; i++)
	{
		scanf("%d%d", &in, &out);
		a[i] = in + out;
	}
	int max = -1;
	for (int i = 1; i <= 7; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 1; i <= 7; i++)
	{
		if (a[i] == max)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}
*/
//TODO 1112：最大值和最小值的差
/*
int a[10001];
int main()
{
	int b = 0;
	int c = 10000; //用来比较的，b，c
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &a[i]);

		if (a[i] >= b)
			b = a[i]; //找出最大的数
		if (a[i] <= c)
			c = a[i]; //找出最小的数
	}
	printf("%d", b - c); //输出差
	return 0;
}
*/
//TODO 1113：不与最大数相同的数字之和
/*
int main()
{
	int n, max = -1000001, sum = 0;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != max)
			sum += a[i];
	}
	printf("%d", sum);
	return 0;
}
*/
//TODO 1114：白细胞计数
/*
int main()
{
	double n;
	int flag_max, flag_min;
	int i;
	double max = -99999, min = 99999;
	double a[3001], b[3001], sum = 0;
	double average, ave_max = -99999;

	cin >> n; //输入样本数量n

	for (i = 1; i <= n; i++)
	{
		cin >> a[i]; //输入样本值
		if (a[i] > max)
		{
			max = a[i];   //记录最大值
			flag_max = i; //记录最大值位置
		}
		if (a[i] < min)
		{
			min = a[i];   //记录最小值
			flag_min = i; //记录最小值位置
		}
		sum += a[i]; //计算n个样本白细胞数量之和
	}
	average = 1.0 * (sum - max - min) / (n - 2); //计算平均白细胞数量

	for (i = 1; i <= n; i++)
	{
		if (i != flag_max && i != flag_min) //不计算已舍去的两个样本
		{
			b[i] = a[i] - average; //记录每个样本与平均数之差的绝对值
			if (b[i] < 0)
				b[i] = -b[i];
		}
		else
			b[i] = -99999; //否则赋值最小，使其不可能为最大值
	}
	for (i = 1; i <= n; i++) //找最大的差值
		if (b[i] > ave_max)
			ave_max = b[i];

	printf("%.2lf %.2lf\n", average, ave_max);
	return 0;
}
*/
//TODO 1115：直方图
/*
int main()
{
	int n, max = -1;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > max)
			max = a[i];
	}
	for (int c = 0; c <= max; c++)
	{
		int t = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == c)
				t++;
		}
		printf("%d\n", t);
	}
	return 0;
}
*/
//TODO 1116：最长平台
/*
int main()
{
	int n, length = 1, j = 0;
	scanf("%d", &n);
	int a[n], d[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
			length++;
		else
		{
			d[j++] = length;
			length = 1;
		}
	}
	int max = d[0];
	for (int i = 1; i < j; i++)
	{
		if (d[i] > max)
			max = d[i];
	}
	printf("%d", max);
	return 0;
}
*/
//TODO 1117：整数去重
/*
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", a[0]);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				break;
			else
			{
				if (j + 1 == i)
					printf(" %d", a[i]);
			}
		}
	}
	return 0;
}
*/
//TODO 1118：铺地毯
/*
int main()
{
	int n;
	scanf("%d", &n);
	int a[n], b[n], g[n], k[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	for (int i = n - 1; i >= 0; i--)
	{
		if (((x >= a[i]) && (x <= a[i] + g[i])) && ((y >= b[i]) && (y <= b[i] + k[i])))
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("%d", -1);
	return 0;
}
*/
//TODO 1119：矩阵交换行
/*
int main()
{
	int m, n;
	int a[6][6];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			scanf("%d", &a[i][j]);
	}
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= 5; i++)
		swap(a[m][i], a[n][i]);
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
*/
//TODO 1120：同行列对角线的格
/*
int main()
{
	int N, i, j;
	scanf("%d", &N);
	int a[N + 1][N + 1];
	memset(a, 0, sizeof(a));
	scanf("%d%d", &i, &j);
	for (int m = 1; m <= N; m++)
		printf("(%d,%d) ", i, m);
	printf("\n");
	for (int m = 1; m <= N; m++)
		printf("(%d,%d) ", m, j);
	printf("\n");
	for (int m = 1; m <= N; m++)
	{
		for (int n = 1; n <= N; n++)
		{
			if ((m - n) == (i - j))
				printf("(%d,%d) ", m, n);
		}
	}
	printf("\n");
	for (int m = 1; m <= N; m++)
	{
		for (int n = 1; n <= N; n++)
		{
			if ((m + n) == (i + j))
				printf("(%d,%d) ", n, m);
		}
	}
	return 0;
}
*/
//TODO 1121：计算矩阵边缘元素之和
/*
int main()
{
	int m, n;
	int sum = 0;
	scanf("%d%d", &m, &n);
	int a[m + 1][n + 1];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if ((i == 1) || (j == 1) || (i == m) || (j == n))
				sum += a[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}
*/
//TODO 1122：计算鞍点
/*
int main()
{
	int a[6][6];
	int t = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			scanf("%d", &a[i][j]);
	}
	int flag_1, flag_2;
	for (int i = 1; i <= 5; i++)
	{
		int min = 10000, max = -10000;
		for (int j = 1; j <= 5; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				flag_1 = j;
			}
		}
		for (int k = 1; k <= 5; k++)
		{
			if (a[k][flag_1] < min)
			{
				min = a[k][flag_1];
				flag_2 = k;
			}
		}
		if (max == min)
		{
			t = 0;
			printf("%d %d %d ", flag_2, flag_1, max);
		}
	}
	if (t)
		printf("%s", "not found");
	return 0;
}
*/
//TODO 1123：图像相似度
/*
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int a[(2 * m) + 1][n + 1];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= 2 * m; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	int t = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == a[i + m][j])
				t++;
		}
	}
	float ans = ((1.0 * t) / (m * n)) * 100;
	printf("%.2f", ans);
	return 0;
}
*/
//TODO 1124：矩阵加法
/*
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int a[(2 * m) + 1][n + 1];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= 2 * m; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] += a[i + m][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
*/
//TODO 1125：矩阵乘法
/*
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int a[n + 1][m + 1], b[m + 1][k + 1], c[n + 1][k + 1];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= k; j++)
			scanf("%d", &b[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			for (int l = 1; l <= m; l++)
			{
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	return 0;
}
*/
//TODO 1126：矩阵转置
/*
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
*/
//TODO 1127：图像旋转
/*
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
*/
//TODO 1128：图像模糊处理
/*
int main()
{
	int n, m, a[100][100], i, j, ave2;
	double ave1;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				printf("%d ", a[i][j]);
			else
			{
				ave1 = 1.0 * (a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]) / 5;
				ave2 = (a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]) / 5;
				if (ave1 - ave2 > 0.5)
					printf("%d ", ave2 + 1);
				else
					printf("%d ", ave2);
			}
		}
		printf("\n");
	}
	return 0;
}
*/