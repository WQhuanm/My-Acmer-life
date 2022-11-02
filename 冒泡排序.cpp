#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//冒泡排序
//只要遍历一遍发现有a[i] > a[i + 1]，我就交换，然后标记下一次还要，除非这一次一次交换也没有，这样每轮都能把大的数放后面
//稳定性：稳定
int n;
int a[N];
void bubblesort()
{
	int flag = 1;
	while (flag)
		{
			flag = 0;
			for (int i = 1; i <= n - 1; ++i)
				{
					if (a[i] > a[i + 1])
						{
							flag = 1;
							swap(a[i], a[i + 1]);
						}
				}
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	bubblesort();
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
