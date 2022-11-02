#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//快速排序
//不稳定
//每次取中间为判断值，让左边小于中间这个tmp，右边大于这个tmp，如此移动，分治（每次分俩边，每边又是可以分俩边
int n;
int a[N];
void fastsort(int begin, int end)
{
	int tmp = a[(begin + end) / 2];//先分为俩半
	int l = begin, r = end;//储存头尾
	while (l < r)
		{
			while (a[l] < tmp)l++;
			while (a[r] > tmp)r--;//比中间小就往后
			if (l <= r)//等于也交换，关键是为了l与r的靠近，让最终能l>r
				{
					swap(a[l], a[r]);
					l++;
					r--;
				}
		}
	if (begin < r)fastsort(begin, r);//遍历左,因为此时l>r,所以是begin与r
	if (l < end)fastsort(l, end);//同理
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	fastsort(1, n);
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
