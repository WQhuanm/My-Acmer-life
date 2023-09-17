#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 1e5 + 10;

int n, rt, sum_sz;
bool vis[N];
int mx[N], sz[N], rfa[N], rnx[N];
ll sum[N][2], val[N], book[N];
map<int, int>dis[N];

vector<pii> edge[N];
vector<int>nx[N];

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

void cal(int u, int f)
{
	for (auto [v, w] : edge[u])if (!vis[v] && v != f)
			{
				dis[rt][v] = dis[rt][u] + w;
				cal(v, u);
			}
}

void re_tree(int u)
{
	vis[u] = 1;
	rt = u, dis[u][u] = 0, cal(u, 0);
	for (auto [v, w] : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = sz[v];
				get_rt(v, 0), get_rt(rt, 0);
				rfa[rt] = u, rnx[rt] = v;
				nx[u].push_back(rt);
				re_tree(rt);
			}
}

void update(int u, int w)
{
	for (int i = u; i; i = rfa[i])
		{
			val[i] += w;
			sum[i][0] += 1ll * dis[i][u] * w;
			if (rfa[i])sum[i][1] += 1ll * dis[rfa[i]][u] * w;
		}
}

ll ask(int u)
{
	ll ans = sum[u][0];
	for (int i = u; rfa[i]; i = rfa[i])
		{
			ans += sum[rfa[i]][0] - sum[i][1] + 1ll * dis[rfa[i]][u] * (val[rfa[i]] - val[i]);
		}
	return ans;
}

ll qask(int u)
{
	ll ans = ask(u);
	for (auto v : nx[u])
		{
			if (ask(rnx[v]) < ans)return qask(v);
		}
	return ans;
}

int q;
void mysolve()
{
	cin >> n >> q;
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	mx[rt = 0] = inf, sum_sz = n;
	get_rt(1, 0), get_rt(rt, 0), rfa[rt] = 0;
	int now = rt;
	re_tree(rt);
	while (q--)
		{
			cin >> x >> y;
			update(x, y);
			cout << qask(now) << endl;
		}
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out2.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
