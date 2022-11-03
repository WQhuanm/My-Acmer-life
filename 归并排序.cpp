#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 120;
//归并排序
//具有稳定性
//这要这一段能分俩部分，就分开，一直到分得只剩一个，然后小部分排完序给，就上一部分继续排序（合并俩个小部分
//每次合并，比较当前左小段与右小段（他们已经排完了），每次取最小，直到俩段全部取完
int n;
int a[N];
int b[N];
void mergesort(int l, int r, int mid)
{
	int ml = l, mr = mid + 1;
	int k = 0;
	while (ml <= mid && mr <= r)
		{
			if (a[ml] <= a[mr])
				{
					b[k++] = a[ml++];
				}
			else
				{
					b[k++] = a[mr++];
				}
		}
	while (ml <= mid)b[k++] = a[ml++];
	while (mr <= r)b[k++] = a[mr++];
	for (int i = 0; i < k; ++i)
		{
			a[i + l] = b[i];
		}
}
void merge(int l, int r)
{
	if (l < r)
		{
			int mid = (l + r) / 2;
			merge(l, mid);
			merge(mid + 1, r);
			mergesort(l, r, mid);
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	merge(1, n);
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
