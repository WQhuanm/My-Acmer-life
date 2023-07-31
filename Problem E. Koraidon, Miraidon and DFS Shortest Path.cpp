#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 5e5 + 10;
vector<int>edge[N];
int dis[N];
bool vis[N];
int n, m;

bool dfs(int u)
{
	vis[u] = 1;
	for (auto v : edge[u])
		{
			if (dis[v] == dis[u])return 0;
			if (!vis[v] && dis[v] < dis[u])return 0;
			if (vis[v] && dis[v] < dis[u])continue;
			if (!dfs(v))return 0;
		}
	vis[u]=0;
	return 1;
}

void mysolve()
{
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; ++i)dis[i] = inf, edge[i].clear(), vis[i] = 0;
	while (m--)
		{
			cin >> x >> y;
			if (x != y)
				{
					edge[x].push_back(y);
				}
		}
	dis[1] = 1;
	queue<int>q;
	q.push(1);
	while (!q.empty())//test16
		{
			int u = q.front();
			q.pop();
			for (auto v : edge[u])if (dis[v] > dis[u] + 1)dis[v] = dis[u] + 1, q.push(v);
		}
	if (dfs(1))cout << "YES" << endl;
	else cout << "NO" << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		{
			mysolve();
		}
	return 0;
}
