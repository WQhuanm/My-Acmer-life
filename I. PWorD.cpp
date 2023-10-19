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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 65;

ll dp[2][N][8], sum[2][8];

int n;

void mysolve()
{
	string s;
	cin >> n >> s;
	s = '$' + s;
	int p = 0;
	sum[p][0] = 1;
	for (int i = 1; i <= n; ++i)
		{
			p ^= 1;
			memset(sum[p], 0, sizeof(sum[p]));
			memset(dp[p], 0, sizeof(dp[p]));
			for (int j = 0; j < 8; ++j)
				{
					if (s[i] == '?')
						{
							for (int k = 0; k < 62; ++k)
								{
									int now = j;
									if (k < 26)now |= 1;
									else if (k < 52)now |= 2;
									else now |= 4;
									dp[p][k][now] = (dp[p][k][now] + sum[p ^ 1][j] - dp[p ^ 1][k][j] + mod) % mod;
								}
						}
					else if ('a' <= s[i] && s[i] <= 'z')
						{
							int now = j | 1, k = s[i] - 'a';
							dp[p][k][now] = (dp[p][k][now] + sum[p ^ 1][j] - dp[p ^ 1][k][j] + mod) % mod;
							now = j | 2, k += 26;
							dp[p][k][now] = (dp[p][k][now] + sum[p ^ 1][j] - dp[p ^ 1][k][j] + mod) % mod;
						}
					else if ('A' <= s[i] && s[i] <= 'Z')
						{
							int	now = j | 2, k = 26 + s[i] - 'A';
							dp[p][k][now] = (dp[p][k][now] + sum[p ^ 1][j] - dp[p ^ 1][k][j] + mod) % mod;
						}
					else
						{
							int	now = j | 4, k = 52 + s[i] - '0';
							dp[p][k][now] = (dp[p][k][now] + sum[p ^ 1][j] - dp[p ^ 1][k][j] + mod) % mod;
						}
				}
			for (int j = 0; j < 8; ++j)for (int k = 0; k < 62; ++k)sum[p][j] = (sum[p][j] + dp[p][k][j]) % mod;
//			for (int j = 0; j < 62; ++j)for (int k = 0; k < 8; ++k)if (dp[p][j][k])printf("dp[%lld][%lld][%lld]:%lld\n", i, j, k, dp[p][j][k]);
		}

	cout << sum[p][7] << endl;
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
