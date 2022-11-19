#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct note
{
	int s, p;
};

vector<note>a[N];
bool vis[N];
int dis[N];

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int>>>q;
	dis[s] = 0;
	q.push({dis[s], s});
	while (!q.empty())
		{
			int tmp = q.top().second;
			q.pop();
			if (vis[tmp])continue;
			vis[tmp] = 1;
			for (int i = 0; i < (int)a[tmp].size(); ++i)
				{
					int j = a[tmp][i].s;
					int k = a[tmp][i].p;
					if (dis[j] > dis[tmp] + k)
						{
							dis[j] = dis[tmp] + k;
							if (!vis[j])
								{

									q.push({dis[j], j});
								}
						}
				}
		}
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	int u, v, w;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			a[u].push_back({v, w});
		}
	dijkstra(s);
	for (int i = 1; i <= n; ++i)
		{
			cout << dis[i] << ' ';
		}
	return 0;
}
