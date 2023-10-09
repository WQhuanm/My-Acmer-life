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
const long long mod = 1e9+7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 310, M = 15;

const int Lim = (1 << 12);

ll dp[N][M][Lim];
int cnt[N], num[Lim];
int n, t, K, m;
void mysolve()
{
	cin >> n >> t >> K >> m;
	int x, lim = (1 << K) - 1;
	for (int k = 0; k <= lim; ++k)for (int i = 0; i < 10; ++i)if ((k >> i) & 1)num[k]++;
	for (int i = 1; i <= n; ++i)cin >> x, cnt[x]++;
	for (int i = 1; i <= t; ++i)cnt[i] += cnt[i - 1];
	dp[0][0][0] = 1;
	for (int i = 1; i <= t; ++i)for (int j = 0; j <= n && j <= i; ++j)
			{
				for (int k = 0; k <= lim; ++k)
					if (num[k] <= m && dp[i - 1][j][k])
						{
							int now = lim & (k << 1);
							dp[i][j][now] = (dp[i][j][now] + dp[i - 1][j][k]) % mod;
							if (cnt[i] > j)dp[i][j + 1][now | 1] = (dp[i][j + 1][now | 1] + dp[i - 1][j][k] * (cnt[i] - j)) % mod;
//							cout << i << "  " << j << "  " << now << "  " << dp[i][j][now] << endl;
//							cout << i << "  " << j+1 << "  " << (now | 1) << "  " << dp[i][j+1][now | 1] << endl;
						}
			}
	ll ans = 0;
	for (int k = 0; k <= lim; ++k)if (num[k] <= m)ans = (ans + dp[t][n][k]) % mod;
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
