#include <bits/stdc++.h>
using namespace std;
//#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define inf 0x3f3f3f3f
#define endl             "\n"
const int N = 3e5 + 10;

const int lg = 20;
int n, rt, sum_sz;
bool vis[N];
int sz[N], mx[N], pre[N][30], dep[N], rfa[N];
int val[N];
vector<int>edge[N], t[N][2];

void get_rt(int u, int f)
{
	sz[u] = 1, mx[u] = 0;
	for (int v : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum_sz - mx[u]);
	if (mx[u] <= mx[rt])rt = u;
}

void pre_dfs(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f;
	for (int i = 1; i < lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (int v : edge[u])if (v != f)pre_dfs(v, u);
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

int get_dis(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

void re_tree(int u)
{
	vis[u] = 1;
	t[u][0].resize(sz[u] + 2);
	if (rfa[u])t[u][1].resize(sz[u] + 2);
	for (int v : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = sz[v];
				get_rt(v, u), get_rt(rt, 0);
				rfa[rt] = u;
				re_tree(rt);
			}
}

void add(int u, int op, int x, int w)
{
	x++;
	for (int i = x; i <= sz[u] + 1; i += i & -i)t[u][op][i] += w;
}

int ask(int u, int op, int x)
{
	if (u > n || u <= 0)return 0;
	x++;
	int ans = 0;
	x = min(x, sz[u] + 1);
	for (int i = x; i > 0; i -= i & -i)ans += t[u][op][i];
	return ans;
}

void change(int u, int w)
{
	for (int i = u; i; i = rfa[i])
		{
			add(i, 0, get_dis(i, u), w);
			if (rfa[i])add(i, 1, get_dis(rfa[i], u), w);
		}
}

int qask(int u, int w)
{
	int ans = ask(u, 0, w);
	for (int i = u; i; i = rfa[i])if (rfa[i])
			{
				int dis = w - get_dis(rfa[i], u);
				ans += ask(rfa[i], 0, dis) - ask(i, 1, dis);
			}

	return ans;
}

int q;
void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> val[i];
	int op, x, y, ans = 0;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	mx[rt = 0] = inf, sum_sz = n;
	get_rt(1, 0), get_rt(rt, 0);
	rfa[rt] = 0, re_tree(rt);
	for (int i = 1; i <= n; ++i)change(i, val[i]);
	while (q--)
		{
			cin >> op >> x >> y;
			x ^= ans, y ^= ans;
		
			if (op)
				{if(x>n||x<=0)continue;
					change(x, y - val[x]), val[x] = y;
				}
			else
				{
					ans = qask(x, y);
					cout << ans << endl;
				}
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
