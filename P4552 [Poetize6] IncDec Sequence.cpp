#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//题目描述
//给定一个长度为n的数列,每次可以选择一个区间[l,r],使这个区间内的数都加 1 或者都减 1。
//请问至少需要多少次操作才能使数列中的所有数都一样，并求出在保证最少次数的前提下，最终得到的数列有多少种。
//思路
//对一个区间操作，其实等价与对差分b[l]与b[r+1]这俩个点操作，
//最终数列全部相等，其实就是除了b[1]，剩下b数列为0，即我多次对不同区间操作，等价多次对差分数值b操作，使最终b[2]到b[n]的值为0
//容易想到，无论数列a加一还是减一，对差分数组b都是一个点+1，一个点-1，那么我们让正数-1，负数+1，这样一步就等于走了俩步，直到只剩正数或者负数，这时候再一步步走
//存在几个数列，因为b[1]不用为0，且b[1]=a[1]=......=a[n],所以，存在几个，就是b[1]能有几种，因为前面正负倆步走不用对b[1]操作，只有一步一步才有可能，所以种类就是abs(zhen-fu)+1(+1是因为自己算一种）
ll a[N];
int main()
{
	int n;
	cin >> n;
	ll zhen = 0, fu = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i >= 2)
				{
					ll c = a[i] - a[i - 1];
					if (c > 0)zhen += c;//记录大于0的差分，统计
					if (c < 0)fu -= c;//记录小于0的差分，统计
				}
		}
	ll ans1 = max(zhen, fu) ; //我们需要最小操作步数是min(zhen,fu)+abs(zhen-fu)等价于max(zhen,fu)
	ll ans2 = abs(zhen - fu) + 1;
	cout << ans1 << '\n' <<  ans2 << endl;
}
