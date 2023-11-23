#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 5e3 + 10, M = 1 << 13;

int n;
bool vis[M];
int a[N*200];
int dp[N][M];
vector<int>b[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[a[i]].push_back(i);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= 5e3; ++i)for (int j = 0; j < M; ++j)if (dp[i][j] <= n)
				{
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
					if (dp[i][j] <= n)vis[j] = 1;
					if (!b[i + 1].empty() && b[i + 1].back() > dp[i][j])
						{
							int now = *upper_bound(b[i + 1].begin(), b[i + 1].end(), dp[i][j]);
							dp[i + 1][j ^ (i + 1)] = min(dp[i + 1][j ^ (i + 1)], now);
						}
				}
	cout << count(vis, vis + M, 1) << endl;
	for (int i = 0; i < M; ++i)if (vis[i])cout << i << " ";
}

signed main()
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
