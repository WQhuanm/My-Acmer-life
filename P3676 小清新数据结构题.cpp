#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 2e5 + 10;

const int lg = 18;
int n, rt, sum_sz;
bool vis[N];
int mx[N], sz[N], dep[N], rfa[N], pre[N][30], val[N], res, tmp[N], a[N], rnx[N];
ll  sum[N][2];
vector<int>edge[N];

void get_rt(int u, int f)//获取当前子树重心rt
{
	sz[u] = 1, mx[u] = 0;
	for (auto v : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum_sz - sz[u]);
	if (mx[u] <= mx[rt])rt = u;
}

void pre_dfs(int u, int f)//预处理原树的距离/深度等信息
{
	tmp[u] = a[u];
	pre[u][0] = f, dep[u] = dep[f] + 1;
	for (int i = 1; i <= lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto v : edge[u])if (f != v)
			{
				pre_dfs(v, u);
				tmp[u] += tmp[v];
			}
}

inline int LCA(int u, int v)
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

inline int get_dis(int x, int y)//获得原树两点距离
{
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

void re_tree(int u, int tot)
{
	vis[u] = 1; //将u的重构子树节点信息存入
	//之后可以用数据结构维护b数组信息
	for (auto v : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = tot - mx[v];
				get_rt(v, 0);
				rfa[rt] = u;
				re_tree(rt, sum_sz);
			}
}

inline void update(int u, int w)
{
	for (int i = u; i; i = rfa[i])
		{
			val[i] += w, sum[i][0] += w * get_dis(i, u);
			if (rfa[i])sum[i][1] += w * get_dis(rfa[i], u);
		}
}

inline ll qask(int u)//以获得u的所有路径信息为例
{
	ll ans = sum[u][0]; //先获得到u子树的信息
	for (int i = u; rfa[i]; i = rfa[i])//获i子树的父亲节点减去i子树节点的信息
		{
			ans += sum[rfa[i]][0] - sum[i][1] + get_dis(rfa[i], u) * (val[rfa[i]] - val[i]);
		}
	return ans;
}

int q;
void mysolve()
{
	cin >> n >> q;
	int x, y, op;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n; ++i)cin >> a[i];
	pre_dfs(1, 0);
	res = tmp[1];
	mx[rt = 0] = inf, sum_sz = n;
	get_rt(1, 0), rfa[rt] = 0;
	re_tree(rt, n);
	ll now = 0;
	for (int i = 1; i <= n; ++i)now += tmp[i] * (res - tmp[i]), update(i, a[i]);
	while (q--)
		{
			cin >> op >> x;
			if (op == 1)
				{
					cin >> y;
					now += (y - a[x]) * qask(x);
					update(x, y - a[x]);
					res += y - a[x];
					a[x] = y;
				}
			else
				{
					ll ans = res * (res + qask(x)) - now;
					cout << ans << endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
