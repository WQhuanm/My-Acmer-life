#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 110;
const int mod = 998244353;

int a[N][N], dp[N][N];

void mysolve()
{
	int n;
	cin >> n;
	bool flag = 1;
	for (int i = 1; i <= n; ++i)
		{
			bool fl = 1;
			for (int j = i; j <= n; ++j)
				{
					cin >> a[i][j];
					if (a[i][j] == 2)fl = 0;
					if (!fl && a[i][j] == 1)flag = 0;
				}
		}
	dp[1][1] = 1;
	if (a[1][1] == 2)flag = 0;
	for (int i = 2; i <= n; ++i)
		{
			if (a[i][i] == 2)
				{
					flag = 0;
					break;
				}
			bool fl = 1;
			int p = i;
			for (int j = i - 1; j; --j)
				{
					if (a[j][i] == 2)fl = 0;
					else if (a[j][i] == 1)
						{
							p = j;
							if (!fl)
								{
									flag = 0;
									break;
								}
						}
				}
			if (!flag)break;
			if (p == i)
				{
					for (int k = 1; k < i; ++k)dp[i][i] = (dp[i][i] + dp[i - 1][k]) % mod;
					p = i - 1;
				}
			for (int j = p; j; --j)
				{
					if (a[j][i] == 2)break;
					else
						{
							dp[i][j] = dp[i - 1][j];
						}
				}
		}
	if (!flag)
		{
			cout << 0 << endl;
			return;
		}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)ans = (ans + dp[n][i]) % mod;
	cout << ans * 2 % mod << endl;
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
