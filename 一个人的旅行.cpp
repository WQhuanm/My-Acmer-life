#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1010;

ll dp[N][N];
ll dis[N];
bool vis[N];
int main()
{
	int t, s, d;
	while (cin >> t >> s >> d)
		{
			int a, b;
			ll x;
			memset(dp, 0x3f, sizeof(dp));
			memset(dis, 0x3f, sizeof(dis));
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= t; ++i)
				{
					cin >> a >> b >> x;
					dp[a][b] = dp[b][a] = min(dp[a][b], x);
				}
			for (int i = 0; i <= 1005; ++i)dp[i][i] = 0;
			for (int i = 1; i <= s; ++i)
				{
					cin >> a;
					dp[0][a] = dp[a][0] = 0;
				}
			for (int i = 1; i <= d; ++i)
				{
					cin >> a;
					dp[1005][a] = dp[a][1005] = 0;
				}

			dis[0] = 0;
			priority_queue< pll, vector<pll>, greater<pll> >q;
			vis[0] = 1;
			q.push({0, 0});

			while (!q.empty())
				{
					ll u = q.top().second;
					q.pop();
					for (ll i = 1; i <= 1005; ++i)if (dis[i] > dis[u] + dp[u][i])
							{
								dis[i] = dis[u] + dp[u][i];
								if (!vis[i])
									vis[i] = 1,	q.push({dis[i], i});
							}
				}
			cout << dis[1005] << endl;
		}

	return 0;
}
