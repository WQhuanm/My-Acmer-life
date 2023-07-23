#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int ll
const int N = 1e5 + 10;

vector<int>edge[N];
int dep[N], fa[N], vis[N];
int n, m, k;

void mysolve()
{
	cin >> n >> m >> k;
	int x, y;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			edge[x].push_back(y), edge[y].push_back(x);
		}
	queue<int>q;
	q.push(1);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : edge[u])if (v != 1)
					{
						if (!dep[v])
							{
								vis[u] = 1;
								dep[v] = dep[u] + 1;
								fa[v] = u;
								if (dep[v] < k)q.push(v);
							}
					}
		}
	ll	ans = 1;
	for (int i = 2; i <= n; ++i)
		{
			if (dep[i] > k || !dep[i])continue;
			int cnt = 0;
			for (auto v : edge[i])
				{
					if (fa[v] == i || fa[i] == v)continue;
					cnt++;
				}
			if (!vis[i])cnt = max(cnt, 1ll);
			ans += cnt * (k - dep[i]) + 1;
		}
	cout << ans << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用asdread请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
