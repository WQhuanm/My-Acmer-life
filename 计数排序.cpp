#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 110;
//计数排序
//有稳定性，因为存入b数组con后往前，这样保证原来相同大小的排在后面的还在后面
int n;
int a[N];
int b[N];
int k[N];
void countsort()
{
	for (int i = 1; i <= n; ++i)
		k[a[i]]++;//记录a[i]这个数值出现多少次
	for (int i = 1; i <= 100; ++i)
		k[i] += k[i - 1];//后面加上前面，最后k[n]就是所有数的个数了，对应的k[a[i]]也就表示包含排在他前面的，自己排在第几个
	for (int i = n; i >= 1; --i)//逆序，保稳定性
		b[k[a[i]]--] = a[i];//假设a[i]这个值出现3次，排序后分别排在12，13，14三个位置，那么k[a[i]]就从14开始，用一次，减少一次，而他表示的值，就是a[i]要填入的位置
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	countsort();
	for (int i = 1; i <= n; ++i)cout << b[i] << " ";
	return 0;
}
