#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 1010;

int n, m;
int ans, cnt;
bool vis[N], book[N];
int tmp[N];
int a[20][N];
vector<int>now;

void dfs(int i)
{
	if (i == m + 1)
		{
			if (cnt)return;
			for (auto v : now)book[v] = 1;
			return;
		}
	if (m - i + 1 < cnt)return;
	vector<int>tp;
	for (int p = 1; p <= m; ++p)if (!vis[a[i][p]])
			{
				vis[a[i][p]] = 1;
				now.push_back(a[i][p]);
				if (tmp[a[i][p]])cnt--;
				dfs(i + 1);
				now.pop_back();
				vis[a[i][p]] = 0;

				cnt++;
				if (!tmp[a[i][p]])tmp[a[i][p]] = i,  tp.push_back(a[i][p]);
			}
	for (auto v : tp)tmp[v] = 0, cnt--;
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j];
	dfs(1);
	vector<int>res;
	for (int i = 1; i <= n; ++i)if (book[i])res.push_back(i);
	cout << res.size() << endl;
	for (auto v : res)cout << v << " ";
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
