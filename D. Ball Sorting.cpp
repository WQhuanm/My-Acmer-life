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
const int N = 3e5 + 10;
const int mod = 998244353;

int a[N];
int n;

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	a[n + 1] = n + 1;
	vector dp(n + 2, vector<int>(n + 2, inf));
	for (int i = 0; i <= n + 1; ++i)dp[0][i] = 0;
	for (int i = 1; i <= n + 1; ++i)for (int j = 0; j < i; ++j)
			{
				if (a[j] < a[i])
					{
						for (int k = 0; k <= n; ++k)
							{
								if (j + 1 == i)dp[i][k] = min(dp[i][k], dp[j][k]);
								if (k)dp[i][k] = min(dp[i][k], dp[j][k - 1] + i - j - 1);
							}
					}
			}
	for (int i = 1; i <= n; ++i)cout << dp[n + 1][i] << " \n"[i == n];
}

int32_t main()
{
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
