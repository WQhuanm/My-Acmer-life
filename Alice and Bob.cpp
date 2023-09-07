#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define  inf 0x3f3f3f3f
#define int ll
typedef pair<int, int> pii;
const int N = 3e3 + 10;

int n;
int dp[2][N][N], pl[N], pr[N], headl[2][N], taill[2][N], headr[2][N], tailr[2][N], a[N];
pii ql[2][N][N], qr[2][N][N];
ll sum[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)for (int j = i; j <= n; ++j)dp[0][i][j] = inf, dp[1][i][j] = -1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i], sum[i] = sum[i - 1] + a[i];
			dp[0][i][i] = a[i], pr[i] = i, pl[i] = i - 1;
			headl[1][i] = headr[1][i] = 1, taill[1][i] = tailr[1][i] = 0;
			headl[0][i] = taill[0][i] = headr[0][i] = tailr[0][i] = 1, ql[0][i][1] = qr[0][i][1] = {a[i], i};
		}
	for (int len = 2; len <= n; ++len)for (int i = 1; i + len - 1 <= n; ++i)
			{
				int j = i + len - 1;
				while (pr[i] != j && sum[pr[i]] - sum[i - 1] < sum[j] - sum[pr[i]])pr[i]++; //sum[l][p]>=sum[p+1][r]
				while (pl[j] != i - 1 && sum[pl[j]] - sum[i - 1] >= sum[j] - sum[pl[j]])pl[j]--; //sum[l][p]<sum[p+1][r]

				while (headl[1][j] <= taill[1][j] && ql[1][j][headl[1][j]].second > pl[j] + 1)headl[1][j]++; //取[1~pl[r]+1,r]
				while (headl[0][j] <= taill[0][j] && ql[0][j][headl[0][j]].second > pl[j] + 1)headl[0][j]++;
				while (headr[1][i] <= tailr[1][i] && qr[1][i][headr[1][i]].second < pr[i])headr[1][i]++; //取[l,pr[i]~r]
				while (headr[0][i] <= tailr[0][i] && qr[0][i][headr[0][i]].second < pr[i])headr[0][i]++; //取[l,pr[i]~r]
				if (pr[i] != j)
					{
						if (headr[0][i] <= tailr[0][i])dp[1][i][j] = max(dp[1][i][j], qr[0][i][headr[0][i]].first);
//						if (headr[1][i] <= tailr[1][i])dp[0][i][j] = min(dp[0][i][j], qr[1][i][headr[1][i]].first);
					}
				if (pl[j] != i - 1)
					{
						if (headl[0][j] <= taill[0][j])dp[1][i][j] = max(dp[1][i][j], ql[0][j][headl[0][j]].first);
//						if (headl[1][j] <= taill[1][j])dp[0][i][j] = min(dp[0][i][j], ql[1][j][headl[1][j]].first);
					}
				if (~dp[1][i][j])
					{
						while (headl[1][j] <= taill[1][j] && ql[1][j][taill[1][j]].first >= dp[1][i][j])taill[1][j]--;
						ql[1][j][++taill[1][j]] = {dp[1][i][j], i};
						while (headr[1][i] <= tailr[1][i] && qr[1][i][tailr[1][i]].first >= dp[1][i][j])tailr[1][i]--;
						qr[1][i][++tailr[1][i]] = {dp[1][i][j], j};

					}
				else
					{
						if (pr[i] != j)
							{
								if (headr[1][i] <= tailr[1][i])dp[0][i][j] = min(dp[0][i][j], qr[1][i][headr[1][i]].first);
							}
						if (pl[j] != i - 1)
							{
								if (headl[1][j] <= taill[1][j])dp[0][i][j] = min(dp[0][i][j], ql[1][j][headl[1][j]].first);
							}
						if (dp[0][i][j] != inf)
							{
								while (headl[0][j] <= taill[0][j] && ql[0][j][taill[0][j]].first <= dp[0][i][j])taill[0][j]--;
								ql[0][j][++taill[0][j]] = {dp[0][i][j], i};
								while (headr[0][i] <= tailr[0][i] && qr[0][i][tailr[0][i]].first <= dp[0][i][j])tailr[0][i]--;
								qr[0][i][++tailr[0][i]] = {dp[0][i][j], j};
							}
					}

			}
	if (~dp[1][1][n])cout << "Alice " << dp[1][1][n] << endl;
	else cout << "Bob " << dp[0][1][n] << endl;
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
//	system("pause");
	return 0;
}
