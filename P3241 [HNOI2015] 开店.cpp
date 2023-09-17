#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 2e5 + 10;

struct node
{
	int x;
	ll y;
	bool operator<(const node&k)const
	{
		if (x != k.x)return x < k.x;
		else return y < k.y;
	}
	node operator+(const node&k)const
	{
		return {x + k.x, y + k.y};
	}
};
vector<node>b[N][2];
vector<pii>edge[N];
const int lg = 20;

int n, rt, sum_sz;
bool vis[N];
int mx[N], sz[N], dep[N], rfa[N], pre[N][30];
ll dis[N];
int a[N];

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
	b[rt][0].push_back({a[u], get_dis(u, rt)});
	if (rfa[rt])b[rt][1].push_back({a[u], get_dis(rfa[rt], u)});
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)cal(v, u);
}

void re_tree(int u)
{
	vis[u] = 1;
	rt = u, cal(u, 0);
	sort(b[u][0].begin(), b[u][0].end()), sort(b[u][1].begin(), b[u][1].end());
	for (int i = 1; i < sz[u]; ++i)
		{
			b[u][0][i].y += b[u][0][i - 1].y;
			if (rfa[u])b[u][1][i].y += b[u][1][i - 1].y;
		}
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = sz[v];
				get_rt(v, 0), get_rt(rt, 0);
				rfa[rt] = u, re_tree(rt);
			}
}

int find(int u, int op, int x)
{
	int l = 0, r = sz[u] - 1, ans = -1;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (b[u][op][mid].x <= x)ans = mid, l = mid + 1;
			else r = mid - 1;
		}
	return ans;
}

pair<ll, int> ask(int u, int op, int l, int r) //传入l-1
{
	r = find(u, op, r), l = find(u, op, l);
	if (~r)
		{
			if (~l)return {b[u][op][r].y - b[u][op][l].y, r - l};
			else return {b[u][op][r].y, r + 1};
		}
	else return {0, 0};
}

ll qask(int u, int l, int r)
{
	ll ans = ask(u, 0, l - 1, r).first;
	for (int i = u; rfa[i]; i = rfa[i])
		{
			ll tmp = get_dis(u, rfa[i]);
			pair<ll, int> pr = ask(rfa[i], 0, l - 1, r), pl = ask(i, 1, l - 1, r);
			ans += pr.first + tmp * pr.second - pl.first - pl.second * tmp;
		}
	return ans;
}

int Q, A;
void mysolve()
{
	cin >> n >> Q >> A;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	dis[1] = 0;
	pre_dfs(1, 0);

	mx[rt = 0] = inf, sum_sz = n;
	get_rt(1, 0), get_rt(rt, 0), rfa[rt] = 0;
	re_tree(rt);
	ll ans = 0;
	while (Q--)
		{
			cin >> w >> x >> y;
			x = (x + ans) % A, y = (y + ans) % A;
			if (x > y)swap(x, y);
			ans = qask(w, x, y);
			cout << ans << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
