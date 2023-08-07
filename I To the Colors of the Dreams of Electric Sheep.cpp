#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
const int N = 5e5 + 10;

struct node
{
	int to, next;
} edge[N << 1];

int dep[N], head[N], pre[N][23], cnt[N][23], to[N][63];
ll val[N][23];
ll a[N];
int num;

const int lg = 21; //5e5

inline void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	pre[u][0] = f;
	val[u][0] = a[f] & a[u];

	for (int i = 0; i < 60; ++i)if ((a[u] >> i) & 1)
			{
				if ((a[f] >> i) & 1)to[u][i] = to[f][i];
				else to[u][i] = u;
			}
	cnt[u][0] = u;
	for (int i = 0; i < 60; ++i)if ((a[u] >> i) & 1)
			{
				if (dep[to[u][i]] < dep[cnt[u][0]])cnt[u][0] = to[u][i];
			}
	for (int i = 1; i < lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
			val[u][i] = val[pre[u][i - 1]][i - 1] & val[u][i - 1];
			cnt[u][i] = cnt[cnt[u][i - 1]][i - 1];
		}
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v != f)dfs1(v, u);
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

int n, q;
void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, add(x, y), add(y, x);
	dfs1(1, 0);
	while (q--)
		{
			cin >> x >> y;
			int lca = LCA(x, y);
			int ans = dep[x] + dep[y] - 2 * dep[lca];
			int tmp = 0;
			for (int i = lg; ~i; --i)if (dep[cnt[x][i]] > dep[lca])
					{
						x = cnt[x][i], tmp += 1 << i;
					}
			if (x != lca)tmp++;
			if (tmp)tmp--;
			ans += tmp;
			tmp = 0;
			ll a = (1ll << 62) - 1;
			int len = dep[x] - dep[lca];
			for (int i = lg; ~i; --i)if (len >= 1 << i)len -= 1 << i, a &= val[x][i], x = pre[x][i];
			for (int i = lg; ~i; --i)if (dep[cnt[y][i]] > dep[lca])
					{
						y = cnt[y][i], tmp += 1 << i;
					}
			if (y != lca)tmp++;
			if (tmp)tmp--;
			ans += tmp;
			ll b = (1ll << 62) - 1;
			len = dep[y] - dep[lca];
			for (int i = lg; ~i; --i)if (len >= 1 << i)
					len -= 1 << i, b &= val[y][i], y = pre[y][i];
			if (!a || !b)ans = -1;
			else if (!(a & b))ans++;
			cout << ans << endl;
		}
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
