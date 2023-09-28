#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 1e3 + 10;

int n, m;
int dp[N][N], a[N][N];
int cnt[N * N];

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)cnt[i] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				{
					cin >> a[i][j];
					if (a[i][j] == a[i - 1][j - 1])
						{
							int len = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
							dp[i][j] = len + 1;
						}
					else
						{
							dp[i][j] = 1;
						}
				}
		}

	for (int i = 1; i <= n; ++i)for (int j = m, l = m + 1; j; --j)
			{
				if (l > j)cnt[a[i][j]]++, l--;
				int p = j - dp[i][j] + 1;
				while (p < l)
					{
						if (!cnt[a[i][l - 1]] && !cnt[a[i - j + l - 1][j]] && a[i][l - 1] != a[i - j + l - 1][j])
							{
								cnt[a[i][l - 1]] = 1, cnt[a[i - j + l - 1][j]] = 1, l--;
							}
						else break;
					}
				ans += j - l + 1;
				cnt[a[i - j + l][j]]--;
				if (l < j)cnt[a[i - j + l + 1][j]]--;
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
