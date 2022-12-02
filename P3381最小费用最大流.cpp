#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int n, m, s, t;
int num;
int dis[N];
bool vis[N];
ll in[N];
int pre[N];
ll ans1, ans2;
struct node
{
	ll to, next, w, c;
} edge[N];
int head[N];

void add(ll u, ll v, ll w, ll c)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	edge[num].c = c;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;///////
	edge[num].c = -c;///////////
	head[v] = num;
}
int bfs()
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	vis[s] = 1;
	in[s] = INF;
	queue<int>q;
	q.push(s);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			vis[x] = 0;
			for (int i = head[x]; i; i = edge[i].next)
				{
					if (!edge[i].w)continue;
					int v = edge[i].to;

					if (dis[v] > dis[x] + edge[i].c)
						{
							dis[v] = dis[x] + edge[i].c;
							in[v] = min(in[x], edge[i].w);
							pre[v] = i;
							if (!vis[v])vis[v] = 1, q.push(v);
						}
				}
		}
	return dis[t] != INF;
}
void update()
{
	int v = t;
	while (v != s)
		{
			int tmp = pre[v];
			edge[tmp].w -= in[t];
			edge[tmp ^ 1].w += in[t];
			v = edge[tmp ^ 1].to;
		}
	ans1 += in[t];
	ans2 += in[t] * dis[t];
}
int main()
{
	cin >> n >> m >> s >> t;
	ll u, v, w, c;
	num = 1;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w >> c;
			add(u, v, w, c);
		}
	ans1 = 0, ans2 = 0;
	while (bfs())
		{
			update();
		}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
