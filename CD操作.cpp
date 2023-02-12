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
const int N = 1e5 + 10;

int pre[N][32], head[N], num, n, m, dis[N], in[N];
map<string, int>mp;
struct node
{
	int next, to;
} edge[N];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}
void init()
{
	memset(head, 0, sizeof(head));
	memset(dis, 0, sizeof(head));
	memset(in, 0, sizeof(in));
	mp.clear();
	num = 0;
}
void dfs(int u, int fa)
{
	dis[u] = dis[fa] + 1;
	pre[u][0] = fa;
	for (int i = 1; pre[u][i - 1]; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v != fa)dfs(v, u);
		}
}

int lca(int u, int v)
{
	if (dis[u] > dis[v])swap(u, v);
	int k = log2(dis[v] - dis[u]);
	for (int i = k; i >= 0; --i)if (dis[pre[v][i]] >= dis[u])v = pre[v][i];
	if (u == v)return v;
	k = log2(dis[v]);
	for (int i = k; i >= 0; --i)
		{
			if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
		}
	return pre[v][0];
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	string x, y;
	cin >> t;
	while (t--)
		{
			int k = 0;
			cin >> n >> m;
			init();
			for (int i = 1; i < n; ++i)
				{
					cin >> x >> y;
					if (!mp[x])mp[x] = ++k;
					if (!mp[y])mp[y] = ++k;
					add(mp[y], mp[x]);
					in[mp[x]]++;
				}
			for (int i = 1; i <= n; ++i )if (!in[i])
					{
						dfs(i, 0);
						break;
					}
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					int h = lca(mp[x], mp[y]);
					int ans = 0;
					if (h != mp[y])ans++;
					ans += dis[mp[x]] - dis[h];
					cout << ans << endl;
				}
		}

	return 0;
}
