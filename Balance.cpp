#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int mod = 51123987;
const int N = 155, M = 53;

int dp[N][M][M][M];
int n;
int nx[N][3];
void mysolve()
{
	string s;
	cin >> n >> s;
	s = '$' + s;
	nx[n][0] = nx[n][1] = nx[n][2] = n + 1;
	for (int i = n; ~i ; --i)
		{
			memcpy(nx[i], nx[i + 1], sizeof(nx[i]));
			if (i) nx[i][s[i] - 'a'] = i;
		}
	ll ans = 0;
	dp[1][0][0][0] = 1;
	int lim = (n + 2) / 3;
	for (int i = 1; i <= n; ++i)
		{
			for (int a = 0; a <= lim; ++a)for (int b = 0; b <= lim && a + b <= 2 * lim; ++b)for (int c = 0; c <= lim && a + b + c <= n; ++c)
						{
							if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(a - c) <= 1)ans = (ans + dp[i][a][b][c]) % mod;
							dp[nx[i][0]][a + 1][b][c] = (dp[nx[i][0]][a + 1][b][c] + dp[i][a][b][c]) % mod;
							dp[nx[i][1]][a ][b + 1][c] = (dp[nx[i][1]][a][b + 1][c] + dp[i][a][b][c]) % mod;
							dp[nx[i][2]][a ][b][c + 1] = (dp[nx[i][2]][a][b][c + 1] + dp[i][a][b][c]) % mod;
						}
		}

	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
