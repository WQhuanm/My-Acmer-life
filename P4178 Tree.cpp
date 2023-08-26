#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 3e5 + 10;
const int M = 2e4;

int n, k, rt, sum;
ll ans = 0;
bool vis[N];
int t[N], dis[N], q[N], qt[N], sz[N], mx[N];
vector<pii>edge[N];

void add(int x, int w)
{
	for (int i = x; i <= M; i += i & -i)t[i] += w;
}

int ask(int x)
{
	if (x < 0)return 0;
	if (!x)return t[0];
	int ans = t[0];
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void get_rt(int u, int f)
{
	sz[u] = 1, mx[u] = 0;
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum - mx[u]);
	if (mx[u] < mx[rt])rt = u;
}

void get_dis(int u, int f)
{
	q[++q[0]] = dis[u];
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)
			{
				dis[v] = dis[u] + w;
				get_dis(v, u);
			}
}

void cal(int u)
{
	int cnt = 0;
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				q[0] = 0, dis[v] = w;
				get_dis(v, u);
				for (int i = q[0]; i; --i)ans += ask(k - q[i]);
				for (int i = q[0]; i; --i)add(q[i], 1), qt[++cnt] = q[i];
			}
	for (int i = cnt; i; --i)add(qt[i], -1);
}

void solve(int u)
{
	vis[u] = 1, cal(u);
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				rt = 0, sum = sz[v];
				get_rt(v, u), get_rt(rt, 0);
				solve(rt);
			}
}
void mysolve()
{
	cin >> n;
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	cin >> k;
	t[0] = 1, mx[rt = 0] =1e9, sum = n;
	get_rt(1, 0), get_rt(rt, 0);
	solve(rt);
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
