#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
void mymin()
{
	int n;
	string a, b;
	cin >> n;
	cin >> a >> b;
	a = "?" + a;
	b = "?" + b;
	int count = 0;
	int c0 = 0;//记录0的个数
	for (int i = 1; i <= n; ++i)
		{
			count += (a[i] == b[i]);//相等时表示为1，count+1，不相等就是0
			if (a[i] == '0')c0++;
		}

	if (count ^ 0 && count ^ n)//count^n,只要count不为n，那么就是真（因为是则异或为0，为假），就是不符合情况，0，同理，所以，只有同时不为0且不为1，跳出
		{
			cout << "NO" << endl;
			return ;
		}
	vector<pair<int, int> >v;
	if (count) //count为n
		{
			for (int i = 1; i <= n; ++i)
				{
					if (a[i] == '0')v.push_back({i, i});
				}
			if (c0 % 2) //a有奇数个0
				v.push_back({1, n});
			else //偶数个0
				{
					v.push_back({1, 1});
					v.push_back({2, n});
				}
		}
	else //count为0
		{
			for (int i = 1; i <= n; ++i)
				{
					if (a[i] == '0')v.push_back({i, i});
				}
			if (c0 % 2)//奇数个0
				{
					v.push_back({1, 1});
					v.push_back({2, n});
				}
			else
				{
					v.push_back({1, n});
				}
		}
	int h = (int)v.size();
	cout << "YES" << endl;
	cout << h << endl;
	for (int i = 0; i < (int)v.size(); ++i)
		{
			cout << v[i].first << ' ' << v[i].second << endl;
		}

}
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			mymin();
		}
	system("pause");
	return 0;
}
