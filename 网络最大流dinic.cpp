#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const ll INF = 1ll << 40;
const int N = 5600;
int n, m, s, t;
ll num = 1;
ll ans;
struct node
{
	ll to, next, w;
} edge[520000 + 100];
ll le[N][N];
ll now[520000 + 100];
ll head[520000 + 100];
int dis[520000 + 100];

void add(ll  u, ll v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;
}

int bfs()
{
	memset(dis, 0, sizeof(dis));
	queue<int>q;
	dis[s] = 1;
	now[s] = head[s];
	q.push(s);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					ll w = edge[i].w;
					if (dis[v] || !w)continue;
					dis[v] = dis[x] + 1;
					now[v] = head[v];
					q.push(v);
					if (v == t)return 1;
				}

		}

	return 0;
}

ll dfs(int x, ll sum)
{
	if (x == t)return sum;
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next) //i&&sum，sum为0也没必要下去了
		{
			now[x] = i;
			int v = edge[i].to;
			if (edge[i].w && dis[v] == dis[x] + 1)
				{
					k = dfs(v, min(sum, edge[i].w));
					edge[i].w -= k;
					edge[i ^ 1].w += k;
					res += k;
					sum -= k;
				}
		}
	return res;
}

int main()
{
	cin >> n >> m >> s >> t;
	ll u, v, w;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			if (!le[u][v])
				{
					add(u, v, w);
					le[u][v] = num - 1;

				}
			else
				{
					edge[le[u][v]].w += w;
				}
		}
	ans = 0;
	while (bfs())
		{
			ans += dfs(s, INF);
		}
	cout << ans << endl;
	return 0;
}
