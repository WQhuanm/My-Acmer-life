#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<ll, ll> pii;
#define endl             "\n"
//#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 1e5 + 10;

const int lg = 20;

int n, rt, sum_sz;
bool vis[N], book[N];
int mx[N], sz[N], dep[N], rfa[N], pre[N][30];
int ans[N];
ll dis[N];
ll a[N];
int p[N];

vector<pii>b[N], edge[N];

void get_rt(int u, int f)//获取当前子树重心rt
{
	sz[u] = 1, mx[u] = 0;
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum_sz - sz[u]);
	if (mx[u] <= mx[rt])rt = u;
}

void pre_dfs(int u, int f)
{
	pre[u][0] = f, dep[u] = dep[f] + 1;
	for (int i = 1; i <= lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto [v, w] : edge[u])if (f != v)
			{
				dis[v] = dis[u] + w;
				pre_dfs(v, u);
			}
}

int LCA(int u, int v)
{
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)
		{
			if (pre[u][i] != pre[v][i])
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	return pre[v][0];//儿子的父亲才是LCA
}

ll get_dis(int x, int y)
{
	return dis[x] + dis[y] - 2 * dis[LCA(x, y)];
}

void cal(int u, int f)
{
	b[rt].push_back({a[u] - get_dis(u, rt), u});
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)cal(v, u);
}

void re_tree(int u)
{
	vis[u] = 1;
	rt = u, cal(u, 0);
	sort(b[u].begin(), b[u].end(), greater<pii>()), p[u] = 0;
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = sz[v];
				get_rt(v, 0), get_rt(rt, 0);
				rfa[rt] = u, re_tree(rt);
			}
}

void init()
{
	for (int i = 1; i <= n; ++i)edge[i].clear(), vis[i] = book[i] = 0, ans[i] = inf, b[i].clear();
	ans[1] = 0;
}

void mysolve()
{
	cin >> n;
	init();
	for (int i = 2; i <= n; ++i)cin >> a[i];
	int x, y;
	ll w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	dis[1] = 0;
	pre_dfs(1, 0);
	mx[rt = 0] = inf, sum_sz = n;
	get_rt(1, 0), get_rt(rt, 0), rfa[rt] = 0;
	re_tree(rt);
	queue<int>q;
	q.push(1), book[1] = 1;
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = u; i; i = rfa[i])
				{
					ll tmp = get_dis(i, u);
					while (p[i] < (int)b[i].size() && b[i][p[i]].first >= tmp)
						{
							int v = b[i][p[i]].second;
							if (!book[v])q.push(v), book[v] = 1;
							ans[v] = min(ans[v], ans[u] + 1);
							p[i]++;
						}
				}
		}
	for (int i = 2; i <= n; ++i)cout << (ans[i] < inf ? ans[i] : -1) << " \n"[i == n];
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
