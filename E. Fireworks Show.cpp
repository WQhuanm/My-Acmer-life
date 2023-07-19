#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 1e5 + 10;
const int mod = 998244353;

pii a[N];
deque<int> vis[N][2];
int pass[N];

void mysolve()
{
	int n;
	cin >> n;
	queue<int>q;
	int p = n + 1;
	vector<pii>ans;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].first >> a[i].second;
			if (a[i].first != a[i].second)
				{
					vis[a[i].first][0].push_back(i), q.push(i);
					vis[a[i].second][1] .push_back(i);
				}
		}
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (pass[a[u].second] || pass[a[u].first])continue;
			int x = a[u].first, y = a[u].second;
			pass[y] = 1;
			if (vis[y][1].size() > 1) //顶部
				{
					int v;
					if (vis[y][1].back() == u)v = vis[y][1].front();
					else v = vis[y][1].back();
					ans.push_back({u, p}), ans.push_back({v, p});
					y = a[v].first;
					if (y == x)
						{
							ans.push_back({u, v});
							p = u;
						}
					else
						{
							int p1 = u;
							while (!vis[x][1].empty())
								{
									ans.push_back({vis[x][1].front(), p1});
									pass[x] = 1;
									p1 = vis[x][1].front(), x = a[p1].first;
								}
							int p2 = v;
							y = a[v].first;
							while (!vis[y][1].empty())
								{
									ans.push_back({vis[y][1].front(), p2});
									pass[y] = 1;
									p2 = vis[y][1].front(), y = a[p2].first;
								}
							ans.push_back({p1, p2});
							if (y == x)pass[x] = 1;
							else
								{
									a[p2].second = x, q.push(p2), vis[x][1] .push_back(p2);
									if (vis[x][0].front() == p1)vis[x][0].pop_front();
									else vis[x][0].pop_back();
								}
							p = p1;
						}
				}
			else//底部
				{
					int v = vis[y][0].front();
					ans.push_back({v, p}), ans.push_back({u, v});
					pass[y] = 1;
					y = a[v].second;
					if (vis[y][1].front() == v)vis[y][1].pop_front();
					else vis[y][1].pop_back();
					vis[y][0].push_back(p);
					a[p].first = y;
					v = p;
					if (y == x)
						{
							pass[y] = 1;
							ans.push_back({u, p});
							p = u;
						}
					else
						{
							int p1 = u;
							while (!vis[x][1].empty())
								{
									ans.push_back({vis[x][1].front(), p1});
									pass[x] = 1;
									p1 = vis[x][1].front(), x = a[p1].first;
								}
							int p2 = v;
							while (!vis[y][1].empty())
								{
									ans.push_back({vis[y][1].front(), p2});
									pass[y] = 1;
									p2 = vis[y][1].front(), y = a[p2].first;
								}
							ans.push_back({p1, p2});
							if (y == x)pass[x] = 1;
							else a[p2].second = x, q.push(p2), vis[x][1] .push_back(p2);
							if (vis[x][0].front() == p1)vis[x][0].pop_front();
							else vis[x][0].pop_back();
							p = p1;
						}
				}
		}
	cout << (int)ans.size() << endl;
	for (pii v : ans)cout << v.first << " " << v.second << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
