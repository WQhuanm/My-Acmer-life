#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e6 + 10;

const int lg = 20;
int n, m;
int dfncnt, top, cnt, tot;
int dfn[N], low[N], sta[N], val[N], pre[N][30], dep[N], idx[N];
vector<int> edge[N], eg[N];

void tarjan(int u, int f)
{
	dfn[u] = low[u] = ++dfncnt;
	sta[++top] = u;
	bool fl = 1;
	for (int v : edge[u])
		{
			if (v == f && fl)
				{
					fl = 0;
					continue;
				}
			if (!dfn[v])
				{
					tarjan(v, u);
					low[u] = min(low[u], low[v]);
					if (low[v] >= dfn[u])
						{
							cnt++;
							eg[u].push_back(cnt), eg[cnt].push_back(u);
							while (1)
								{
									int now = sta[top--];
									eg[now].push_back(cnt), eg[cnt].push_back(now);
									if (now == v)break;
								}
						}
				}
			else low[u] = min(low[u], dfn[v]);
		}
}

void dfs(int u, int f)
{
	idx[u] = ++tot;
	pre[u][0] = f, dep[u] = dep[f] + 1;
	val[u] += u <= n;
	for (int i = 1; i <= lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto v : eg[u])if (v != f)
			{
				val[v] = val[u];
				dfs(v, u);
			}
}

int LCA(int u, int v)
{
	if (dep[u] != dep[v])
		{
			if (dep[u] < dep[v])swap(u, v);
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}

int dis(int x, int y)
{
	return val[x] + val[y] - 2 * val[LCA(x, y)];
}

int b[N];
bool cmp(int a, int b)
{
	return idx[a] < idx[b];
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)edge[i].clear(), dfn[i] = 0;
	for (int i = 1; i <= cnt; ++i)eg[i].clear(),val[i]=0;
	dfncnt =tot= 0;
	int x, y;
	while (m--)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	cnt = n;

	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			{
				top = 0, tarjan(i, 0);
			}
	dfs(1, 0);
	int q;
	cin >> q;
	while (q--)
		{
			cin >> y;
			for (int i = 1; i <= y; ++i)cin >> b[i];
			sort(b + 1, b + 1 + y, cmp);
			int ans = 0;
			for (int i = 1; i < y; ++i)ans += dis(b[i], b[i + 1]);
			ans += dis(b[1], b[y]);
			ans = ans / 2 - y + (LCA(b[1], b[y]) <= n);
			cout << ans << endl;
		}
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
