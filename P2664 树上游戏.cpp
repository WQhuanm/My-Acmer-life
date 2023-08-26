#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 3e5 + 10;

int n, sum, rt;
ll val, tmp;
bool vis[N], book[N];
int a[N], color[N], sz[N], mx[N];
ll ans[N];
vector<int>edge[N];

void get_rt(int u, int f)
{
	sz[u] = 1, mx[u] = 0;
	for (auto v : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum - sz[u]);
	if (mx[u] < mx[rt])rt = u;
}

void get_color(int u, int f, int w)
{
	bool fl = 0;
	if (!book[a[u]])fl = book[a[u]] = 1, color[a[u]] += w * sz[u], val += w * sz[u];
	for (auto v : edge[u])if (!vis[v] && v != f)get_color(v, u, w);
	if (fl)book[a[u]] = 0;
}

void dfs(int u, int f)
{
	bool fl = 0;
	if (!book[a[u]])fl = book[a[u]] = 1, val += -color[a[u]] + tmp;
	ans[u] += val;
	for (auto v : edge[u])if (!vis[v] && v != f)dfs(v, u);
	if (fl)book[a[u]] = 0, val -= -color[a[u]] + tmp;
}

void cal(int u)
{
	book[a[u]] = 1, val = sz[u], get_color(u, 0, 1);
	ans[u] += val;
	for (auto v : edge[u])if (!vis[v])
			{
				get_color(v, u, -1), val -= sz[v], tmp = sz[u] - sz[v];
				dfs(v, u);
				get_color(v, u, 1), val += sz[v];
			}
	get_color(u, 0, -1),	book[a[u]] = 0;
}

void solve(int u)
{
	vis[u] = 1, cal(u);
	for (auto v : edge[u])if (!vis[v])
			{
				rt = 0, sum = sz[v];
				get_rt(v, u), get_rt(rt, 0);
				solve(rt);
			}
}
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	mx[rt = 0] = inf, sum = n;
	get_rt(1, 0), get_rt(rt, 0);
	solve(rt);
	for (int i = 1; i <= n; ++i)cout << ans[i] << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
