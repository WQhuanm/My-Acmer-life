#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 5e3 + 10;

int n;
int a[N];

void mysolve()
{
	cin >> n;
	int ans = 0;
	vector vis(n + 1, vector<bool>(n + 1.0));
	vector dp(n + 1, vector<bool>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		{
			vector<bool>book(n + 2);
			dp[i] = dp[i - 1];
			cin >> a[i];
			int mex = 0;
			for (int l = i ; l; --l)
				{
					book[a[l]] = 1;
					if (book[mex])
						{
							while (book[mex])mex++;
							if (!vis[l - 1][mex])
								{
									vis[l - 1][mex] = 1;
									for (int j = 0; j <= l; ++j)if (dp[l - 1][j])dp[i][j ^ mex] = 1;
								}
						}
				}
			for (int j = ans + 1; j <= n; ++j)if (dp[i][j])ans = j;
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
