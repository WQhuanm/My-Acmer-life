#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 10;

struct node
{
	int to, val;
};
vector<node>edge[N];
int n, k, a[N], cnt, b[N];
ll dis[N][1 << 6];

void dfs(int u, int f)
{
	b[++cnt] = u;
	for (auto v : edge[u])if (v.to != f)dfs(v.to, u);
}

void mysolve()
{
	cin >> n >> k;
	int x, y, w;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			if (x)a[i] = 1 << (x - 1);
		}
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y >> w;
			edge[x].push_back({y, w});
			edge[y].push_back({x, w});
		}
	dfs(1, 0);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i)dis[i][a[i]] = 0;
	for (int i = 1; i < (1 << k); ++i)
		{
			for (int j = n; j; --j)for (node v : edge[b[j]])dis[b[j]][i] = min(dis[b[j]][i], v.val + dis[v.to][i]);
			for (int j = 1; j <= n; ++j)for (node v : edge[b[j]])dis[b[j]][i] = min(dis[b[j]][i], v.val + dis[v.to][i]);
			for (int j = 1; j <= n; ++j)if (a[j])dis[j][i | a[j]] = min(dis[j][i | a[i]], dis[j][i]);
		}
	ll ans = INF;
	int p = (1 << k) - 1;
	for (int i = 1; i <= n; ++i)ans = min(ans, dis[i][p]);
	cout << (ans < INF ? ans : -1) << endl;
}
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
