#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pii;
#define endl             "\n"
const int N = 1e6 + 10;

int vis[N];
bool  ok[N], a[N];
vector<pii>edge[N], eg[N];
int n, m, k, nx;
string ans, cur, ans2;

void dfs(int u)
{
	vis[u] = 1;
	for (auto [v, c] : edge[u])if (ok[v])
			{
				if (vis[v] == 1)
					{
						if (ans.empty())cur.push_back(c), ans = cur, nx = v;
						return;
					}
				else if (!vis[v])
					{
						cur.push_back(c);
						dfs(v);
						if (!ans.empty())return;
						cur.pop_back();
					}
			}
	vis[u] = -1;
}

void dfs2(int u)
{
	vis[u] = 1;
	if (a[u])
		{
			if (ans2.empty())ans2 = cur;
			return;
		}
	for (auto [v, c] : edge[u])if (ok[v])
			{
				if (!vis[v])
					{
						cur.push_back(c);
						dfs2(v);
						if (!ans2.empty())return;
						cur.pop_back();
					}
			}
}

void mysolve()
{
	cin >> n >> m >> k;
	int x, y;
	char c;
	queue<int>q;
	for (int i = 1; i <= k; ++i)cin >> x, a[x] =ok[x]= 1, q.push(x);
	while (m--)
		{
			cin >> x >> y >> c;
			edge[x].push_back({y, c});
			eg[y].push_back({x, c});
		}
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto [v, c] : eg[u])if (!ok[v])ok[v]=1,q.push(v);
		}
	if (!ok[1])return cout << -1 << endl, void();
	dfs(1);
	if (ans.empty())return cout << -1 << endl, void();
	fill(vis, vis + n + 1, 0);
	cur.clear();
	dfs2(nx);
	cout << ans + ans2 << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
