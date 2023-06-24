#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 5e3 + 10;
const int mod = 998244353;

vector<int> prefix(string s)
{
	reverse(s.begin(), s.end());
	vector<int>p((int)s.size() + 1);
	p[0] = 0;
	for (int i = 1; i < (int)s.size(); ++i)
		{
			int j = p[i - 1];
			while (j && s[i] != s[j])j = p[j - 1]; //找到匹配的最长前缀长度j
			if (s[i] == s[j])++j;
			p[i] = j;
		}
	return p;
}

ll dp[N];

void mysolve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i)
		{
			vector<int>p = prefix(s.substr(0, i + 1));
			for (int j = i - 1, k = 0; j >= -1; --j, ++k)
				{
					if (!p[k] || (i - j) % (i - j - p[k]))
						{
							dp[i] = (dp[i] + (j == -1 ? 1 : dp[j])) % mod;
						}
				}
		}
	cout << dp[n - 1] << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
