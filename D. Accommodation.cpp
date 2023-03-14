#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
void mysolve()
{
	int n, m;
	cin >> n >> m;
	string s;
	int minn = 0, maxn = 0;
	while (n--)
		{
			cin >> s;
			int two = 0, cnt =  count(s.begin(), s.end(), '1');//先用count记录字符串1的个数
			for (int i = 0; i < m - 1; ++i)if (s[i] == '1' && s[i + 1] == '1')two++, i++;//第一个two记录11对数
			two = min(m / 4, two);
			minn += cnt - two;

			two =  0;//这个two记录不是11的对数
			for (int i = 0; i < m - 1; ++i)if (s[i] != '1' || s[i + 1] != '1')two++, i++;
			two = min(m / 4, two);
			maxn += cnt - (m / 4 - two);
		}
	cout << minn << ' ' << maxn << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mysolve();
	system("pause");
	return 0;
}
