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

int dp[N][N];
int dis[N];
bool vis[N];

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, s, w, a, b, t;
	while (cin >> n >> m >> s)
		{
			memset(vis, 0, sizeof(vis));
			memset(dp, 0x3f, sizeof(dp));
			memset(dis, 0x3f, sizeof(dis));
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b >> t;
					dp[a][b] = min(dp[a][b], t);
				}
			//	for (int i = 1; i <= n; ++i)dp[i][i] = 0;
			cin >> w;
			for (int i = 1; i <= w; ++i)
				{
					cin >> a;
					dp[0][a] = 0;
				}
			dis[0] = 0;
			priority_queue<pii, vector<pii>, greater<pii>>q;
			q.push({0, 0});
			while (!q.empty())
				{
					//	cout << 1 << endl;
					int x = q.top().second;
					q.pop();
					if (vis[x])continue;
					vis[x] = 1;
					for (int i = 1; i <= n; ++i)if (dis[i] > dis[x] + dp[x][i])
							{
								dis[i] = dis[x] + dp[x][i];
								if (!vis[i])
									{
										q.push({dis[i], i});
									}

							}
				}
			if (dis[s] < INF)cout << dis[s] << endl;
			else cout << -1 << endl;
		}

	return 0;
}
