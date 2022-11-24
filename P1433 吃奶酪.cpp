#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

vector<pair<double, double> >vc;
bool vis[100];
double dp[100][100];
double lu[(1 << 16) + 100][20];
double ans;
void dfs(int st, double t, int way, int n)
{
	if (t >= ans)return;
	if (n == 0)
		{
			ans = min(t, ans);
			return;
		}
	for (int i = 1; i < (int)vc.size(); ++i)
		{
			if (!vis[i])
				{
					int tmp = way + (1 << (i - 1));
					if (!lu[tmp][i])lu[tmp][i] = INF * 1.0;
					if (lu[tmp][i] > t + dp[st][i] && t + dp[st][i] < ans)
						{
							lu[tmp][i] = t + dp[st][i];
							vis[i] = 1;
							dfs(i, t + dp[st][i], tmp, n - 1);
							vis[i] = 0;

						}

				}

		}

}

int main()
{
	int n;
	double x, y;
	cin >> n;
	vc.push_back({0.0, 0.0});
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y;
			vc.push_back({x, y});
			for (int j = 0; j < i; ++j)dp[i][j] = dp[j][i] = sqrt((abs(vc[i].first - vc[j].first) * abs(vc[i].first - vc[j].first) + abs(vc[i].second - vc[j].second) * abs(vc[j].second - vc[i].second)));
		}
	ans = INF * 1.00;
	vis[0] = 1;
	dfs(0, 0.0, 0, n);
	printf("%.2lf", ans);
}
