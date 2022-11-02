#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//选择排序
//遍历剩下的数，每次找到最小的
//稳定性：不稳定，swap使相同大小的取后面的一个，改变了原来的顺序
//复杂度：O（n^2)
int a[N];
int n;
void select_sort()
{
	for (int i = 1; i <= n; ++i)
		{
			int k = i;
			for (int j = i + 1; j <= n; ++j)
				{
					if (a[j] < a[k])k = j;
				}
			swap(a[i], a[k]);
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	select_sort();
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
