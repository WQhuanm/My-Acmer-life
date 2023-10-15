#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 3e5 + 10;

int n, a[N], cnt = 0;
bool vis[N];
vector<int>num, q;

bool flag ;

void dfs(int p)
{
	if (p == (int)q.size())return flag = 1, void();
	for (auto v : num)if (!vis[v] && abs(v - a[q[p] - 1]) > 1 && abs(v - a[q[p] + 1]) > 1)
			{
				vis[v] = 1;
				a[q[p]] = v;
				dfs(p + 1);
				if (flag)return;
				a[q[p]] = -1;
				vis[v] = 0;
			}
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (~a[i]) vis[a[i]] = 1;
		}
	set<int>s;
	for (int i = 1; i <= n; ++i)if (!vis[i])s.insert(i);
	a[0] = a[n + 1] = -100;
	cnt = count(a + 1, a + 1 + n, -1);
	if (cnt)
		{
			for (int p = 1; p <= n && cnt >= 15; ++p)
				{
					if (a[p] == -1)
						{
							int now;
							for (auto v : s)
								{
									if (abs(a[p - 1] - v) > 1 && abs(a[p + 1] - v) > 1)
										{
											now = v;
											break;
										}
								}
							a[p] = now, vis[now] = 1, s.erase(now), cnt--;
						}
				}
			for (int i = 1; i <= n; ++i)if (a[i] == -1)q.push_back(i);
			for (int i = 1; i <= n; ++i)if (!vis[i])num.push_back(i);
			dfs(0);
			if (!flag)return cout << -1 << endl, void();
		}
	for (int i = 1; i <= n; ++i)if (a[i] == -1 || abs(a[i] - a[i + 1]) <= 1)return cout << -1 << endl, void();
	for (int i = 1; i <= n; ++i)cout << a[i] << " \n"[i == n];
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
