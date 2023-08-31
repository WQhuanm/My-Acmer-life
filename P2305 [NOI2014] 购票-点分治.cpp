#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, ll> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
const int N = 2e5 + 10;

int n, type, rt, top, cnt;
bool vis[N];
int fa[N], stk[N], sz[N], mx[N], que[N];
ll dis[N], dp[N], lim[N], p[N], q[N];
vector<pii>edge[N];

bool cmp(int a, int b)
{
	return dis[a] - lim[a] > dis[b] - lim[b];
}

void dfs1(int u)
{
	for (auto [v, w] : edge[u])dis[v] = dis[u] + w, dfs1(v);
}

double slope(int a, int b)
{
	return (1.0 * dp[a] - dp[b]) / (1.0 * dis[a] - dis[b]);
}

void get_rt(int u, int sum) //获取当前子树重心rt
{
	sz[u] = 1, mx[u] = 0;
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				get_rt(v, sum);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum - sz[u]);
	if (mx[u] <= mx[rt])rt = u;//////////////////////////////////////////
}

void dfs(int u)
{
	que[++cnt] = u;
	for (auto [v, w] : edge[u])if (!vis[v])dfs(v);
}

void push(int x)
{
	while (top > 1 && slope(stk[top - 1], x) - slope(stk[top - 1], stk[top]) > -eps)top--;
	stk[++top] = x;
}

int find_id(int k)
{
	int l = 1, r = top - 1, ans = top;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (slope(stk[mid], stk[mid + 1]) - k < eps)ans = mid, r = mid - 1;
			else ans = l = mid + 1;
		}
	return stk[ans];
}
void solve(int u, int sum)
{
	if (sum == 1)return;
	rt = 0, get_rt(u, sum);
	int now = rt;
	for (auto [v, w] : edge[now])vis[v] = 1, sum -= sz[v];
	solve(u, sum);
	cnt = top = 0;
	for (auto [v, w] : edge[now])dfs(v);
	sort(que + 1, que + 1 + cnt, cmp);
	int nx = now;
	for (int i = 1; i <= cnt; ++i)
		{
			int y = que[i];
			while (nx != fa[u] && dis[nx] >= dis[y] - lim[y])push(nx), nx = fa[nx];
			if (top)
				{
					int j = find_id(p[y]);
					dp[y] = min(dp[y], dp[j] + (dis[y] - dis[j]) * p[y] + q[y]);
				}
		}
	for (auto [v, w] : edge[now])
		solve(v, sz[v]);
}

void mysolve()
{
	ll w;
	cin >> n >> type;
	for (int i = 2; i <= n; ++i)cin >> fa[i] >> w >> p[i] >> q[i] >> lim[i], edge[fa[i]].push_back({i, w}), dp[i] = INF;
	dfs1(1);
	mx[rt = 0] = inf;
	solve(1, n);
	for (int i = 2; i <= n; ++i)cout << dp[i] << endl;
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
//	system("pause");
	return 0;
}
