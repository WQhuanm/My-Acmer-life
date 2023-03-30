#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int mod = 10007;
int dp[N][N];
int main()
{
	int t, t1 = 0;
	cin >> t;
	while (t--)
		{
			string s;
			cin >> s;
			for (int len = 1; len <= (int)s.size(); ++len)for (int i = 0; i + len - 1 < (int)s.size(); ++i)
					{
						int j = i + len - 1;
						dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + mod) % mod;////+mod
						if (s[i] == s[j])dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] + 1) % mod;
					}
			printf("Case %d: ", ++t1);
			cout << dp[0][s.size() - 1] << endl;
		}
	return 0;
}
