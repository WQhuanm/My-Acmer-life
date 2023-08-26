#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

vector<pii>edge[N];
bool vis[N], book[N * 100];
int dis[N], qur[N], ans[N],  q[N], sz[N], mx[N], qr[N];
int n, m, rt;

void get_rt(int u, int f, int sum)
{
	sz[u] = 1, mx[u] = 0;
	for (auto [v, w] : edge[u])if (v != f && !vis[v])
			{
				get_rt(v, u, sum);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum - sz[u]);
	if (mx[u] < mx[rt])rt = u;
}

void get_dis(int u, int f)
{
	q[++q[0]] = dis[u];
	for (auto [v, w] : edge[u])if (v != f && !vis[v])
			{
				dis[v] = w + dis[u];
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
				for (int i = q[0]; i; --i)for (int k = 1; k <= m; ++k)
						if (qur[k] >= q[i] && book[qur[k] - q[i]])ans[k] |= 1;
				for (int i = q[0]; i; --i)book[q[i]] = 1, qr[++cnt] = q[i];
			}
	for (int i = cnt; i; --i)book[qr[i]] = 0;
}

void solve(int u)
{
	vis[u] = 1, cal(u);
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				rt = 0;
				int sum = sz[v];
				get_rt(v, u, sum), get_rt(rt, 0, sum);
				solve(rt);
			}
}

void mysolve()
{
	cin >> n >> m;
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	for (int i = 1; i <= m; ++i)cin >> x, qur[i] = x;
	rt = 0, book[0] = 1, mx[0] = inf;
	get_rt(1, 0, n), get_rt(rt, 0, n);
	solve(rt);
	for (int i = 1; i <= m; ++i)cout << (ans[i] ? "AYE" : "NAY") << endl;
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
