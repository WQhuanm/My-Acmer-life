#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e7 + 10;

char a[N], b[N];
ll a1[N], b1[N];

int main()
{
	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b);
//a对模板b，取z[i-l],取的是模板部分的z函数，所以我们先求出b的z函数
	b1[0] = lb;//这题规定z[0]=n
	for (int i = 1, l = 0, r = 0; i < lb; ++i)
		{
			if (i <= r && b1[i - l] < r - i + 1)b1[i] = b1[i - l];
			else
				{
					b1[i] = max(0, r - i + 1);
					while (b1[i] + i < lb && b[b1[i]] == b[i + b1[i]])++b1[i];
				}
			if (b1[i] + i - 1 > r)l = i, r = i + b1[i] - 1;
		}
//暴力找a关于模板b的z[0]
	for (int i = 0; i < la; ++i)
		{
			if (b[i] == a[i])++a1[0];
			else break;//不等于直接跳出，不能待着
		}

	for (int i = 1, l = 0, r = 0; i < la; ++i)
		{
			if (i <= r && b1[i - l] < r - i + 1)a1[i] = b1[i - l];//注意，a对模板b，取z[i-l],取的是模板部分的z函数，所以是判断b的z函数的值，取也是b的z函数的值
			else
				{
					a1[i] = max(0, r - i + 1);
					while (i + a1[i] < la && b[a1[i]] == a[i + a1[i]])++a1[i];
				}
			if (i + a1[i] - 1 > r)l = i, r = i + a1[i] - 1;
		}

	ll as = 0, bs = 0;
	for (int i = 0; i < la; ++i)as ^= (i + 1) * (a1[i] + 1);
	for (int i = 0; i < lb; ++i)bs ^= (i + 1) * (b1[i] + 1);
	cout << bs << endl << as << endl;
	return 0;
}
