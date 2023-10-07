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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e3 + 10;

int cnt[N], ans[N], len[N], dp[N][N], bac[N][N];
int n, k;
string s;
void solve()
{
	for (int i = 0; i <= n; ++i)len[i] = -1;
	for (int i = 1; i <= n; ++i)cnt[i] = cnt[i - 1] + (s[i] == '1' ? 1 : 0);

	for (int i = 1; i <= n + 1; ++i)for (int j = 0; j <= k; ++j)dp[i][j] = bac[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j && cnt[i] - cnt[j - 1] <= k; --j)
				{
					dp[i][cnt[i] - cnt[j - 1]] = i - j + 1;
				}
			for (int j = 0; j < k; ++j)dp[i][j + 1] = max({dp[i][j + 1], dp[i][j]});
			for (int j = 0; j <= k; ++j)dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}

	cnt[n + 1] = 0;
	for (int i = n; i; --i)cnt[i] = cnt[i + 1] + (s[i] == '0' ? 1 : 0);
	for (int i = 0; i <= k; ++i)bac[n + 1][i] = 0;
	for (int i = n; i; --i)
		{
			for (int j = i; j <= n && cnt[i] - cnt[j + 1] <= k; ++j)bac[i][cnt[i] - cnt[j + 1]] = j - i + 1;
			for (int j = 0; j < k; ++j)bac[i][j + 1] = max(bac[i][j + 1], bac[i][j]);
			for (int j = 0; j <= k; ++j)bac[i][j] = max(bac[i][j], bac[i + 1][j]);
		}
	for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= k; ++j)len[dp[i][j]] = max(len[dp[i][j]], bac[i + 1][k - j]);
		}
	for (int i = 1; i <= n; ++i)for (int p = 0; p <= n; ++p)if (~len[p])
				{
					ans[i] = max(ans[i], i * p + len[p]);
				}
}

void mysolve()
{
	cin >> n >> k >> s;
	for (int i = 0; i <= n; ++i)ans[i] = 0;
	s = '$' + s;
	solve();
	reverse(s.begin() + 1, s.end());
	solve();
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
