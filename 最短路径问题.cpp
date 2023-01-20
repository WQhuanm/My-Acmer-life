#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e3 + 10;

int dd[N][N], dp[N][N];
int dis[N], v[N];
bool vis[N];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, s, t, a, b, d, p;
	while (cin >> n >> m && (n || m))
		{
			memset(dd, 0x3f, sizeof(dd));
			memset(dp, 0x3f, sizeof(dp));
			memset(dis, 0x3f, sizeof(dis));
			memset(v, 0x3f, sizeof(v));
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b >> d >> p;
					if (dd[a][b] > d)
						{
							dd[a][b] = dd[b][a] = d;
							dp[a][b] = dp[b][a] = p;
						}
					else if (dd[a][b] == d)dp[a][b] = dp[b][a] = min(dp[a][b], p);
				}
			cin >> s >> t;
			priority_queue<pii, vector<pii>, greater<pii>>q;
			dis[s] = 0;
			v[s] = 0;
			q.push({0, s});
			while (!q.empty())
				{
					int u = q.top().second;
					q.pop();
					if (vis[u])continue;
					vis[u] = 1;
					for (int i = 1; i <= n; ++i)
						{
							if (dis[i] >= dis[u] + dd[u][i])
								{
									if (dis[i] > dis[u] + dd[u][i])
										{
											dis[i] = dis[u] + dd[u][i];
											v[i] = dp[u][i] + v[u];
										}
									else
										{
											v[i] = min(v[i], dp[u][i] + v[u]);
										}
									if (!vis[i])q.push({dis[i], i});
								}
						}
				}
			cout << dis[t] << " " << v[t] << endl;

		}

	return 0;
}
