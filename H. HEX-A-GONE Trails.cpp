#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
int n, x, y;
vector<int>edge[N];
int dep[N], fa[N];
bool vis[N];
int dis_y[N], dis_x[N];;
void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for (int v : edge[u])if (v != f)dfs1(v, u);
}

void dfs_y(int u, int f)
{
	dis_y[u] = 0;
	vis[u] = 1;
	for (auto v : edge[u])if (v != f && dep[v] > dep[u])
			{
				dfs_y(v, u);
				dis_y[u] = max(dis_y[v] + 1, dis_y[u]);
			}
}

void dfs_x(int u, int f)
{
	dis_x[u] = 0;
	for (auto v : edge[u])if (v != f && dep[v] > dep[u] && v != y)
			{
				dfs_x(v, u);
				dis_x[u] = max(dis_x[u], dis_x[v] + 1);
			}
}
void mysolve()
{
	cin >> n >> x >> y;
	int u, v;
	for (int i = 1; i <= n; ++i)edge[i].clear(), vis[i] = 0;
	for (int i = 1; i < n; ++i)
		cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u);
	dep[0] = -1;
	dfs1(x, 0);
	priority_queue<pii>q;
	for (int i = 1; i <= n; ++i)q.push({dep[i], i});
	dfs_y(y, fa[y]);
	while (!q.empty() && vis[q.top().second])q.pop();
	int mx = dis_y[y];
	if (mx >= q.top().first)
		{
			cout << 0 << endl;
			return;
		}
	int p = fa[y];
	dfs_x(fa[y], y);
	int son = y, len = 0, x_son = -1;
	while (p != x)
		{
			if (dep[p] - dep[x] <= dep[y] - dep[p])
				{
					if (x_son == -1)
						{
							if (son == y)x_son = -1;
							else dfs_x(son, y), x_son = dis_x[son];
						}
					dfs_x(p, son);
					if (dep[p] + dis_x[p] > len && dep[p] + max(x_son + 1, dis_x[p]) > mx)
						{
							cout << 1 << endl;
							return;
						}
					x_son = max(dis_x[p], x_son + 1);
				}
			dfs_y(p, son);
			while (!q.empty() && vis[q.top().second])q.pop();
			len =  dep[y] - dep[p] + dis_y[p];
			if (len >= q.top().first)
				{
					cout << 0 << endl;
					return;
				}
			son = p, p = fa[p];
		}
	cout << 1 << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		{
			mysolve();
		}
	return 0;
}

