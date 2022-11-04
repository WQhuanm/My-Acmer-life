#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e7 + 100;
int a[N];
void fastsort(int begin, int end)
{
	int mid = a[(begin + end) / 2];
	int l = begin, r = end;
	while (l < r)
		{
			while (a[l] < mid)l++;
			while (a[r] > mid)r--;
			if (l <= r)
				{
					swap(a[r], a[l]);
					l++, r--;
				}
		}
	if (begin < r)fastsort(begin, r);
	if (l < end)fastsort(l, end);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	fastsort(1, n);
	cout << a[k + 1];
	return 0;
}
