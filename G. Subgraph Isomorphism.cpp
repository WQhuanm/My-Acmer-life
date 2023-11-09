#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 3e5 + 10;

int n, m;
vector<int>edge[N];
int in[N];
bool vis[N];

typedef unsigned long long ull;
const ull mask = chrono::steady_clock::now().time_since_epoch().count();
ull shift(ull x)
{
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}

ull sub[N], MARK = 18446744073709551615ULL;
void dfs(int u, int f)
{
	sub[u] = 1;
	for (auto v : edge[u])if (v != f && vis[v])
			{
				dfs(v, u);
				sub[u] += shift(sub[v]);
			}
}
bool dfs2(int u, int f, int top)
{
	for (auto v : edge[u])if (!vis[v] && v != f)
			{
				if (sub[u] == sub[v])return 0;
				if (v == top)return 1;
				return dfs2(v, u, top);
			}
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)edge[i].clear(), vis[i] = 0, in[i] = 0;
	int x, y;
	for (int i = 1; i <= m; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x), in[x]++, in[y]++;

	if (m == n - 1)return cout << "YES" << endl, void();
	if (m > n)return cout << "NO" << endl, void();
	queue<int>q;
	for (int i = 1; i <= n; ++i)if (in[i] == 1)q.push(i), vis[i] = 1;
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : edge[u])if (--in[v] == 1)vis[v] = 1, q.push(v);
		}
	set<ull>s;
	for (int i = 1; i <= n; ++i)if (!vis[i])dfs(i, i), s.insert(sub[i]);
	if ((int)s.size() == 1)cout << "YES" << endl;
	else if ((int)s.size() == 2)
		{
			for (int i = 1; i <= n; ++i)if (!vis[i])
					{
						if (dfs2(i, 0, i))cout << "YES" << endl;
						else cout << "NO" << endl;
						return;
					}
		}
	else cout << "NO" << endl;

}
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)mysolve();
	return 0;
}

