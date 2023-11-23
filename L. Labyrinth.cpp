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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, m, s, t;
vector<int>edge[N];
bool book[N];
vector<int>res;

int vis[N];
int cnt;
bool dfs(int u)
{
	if (vis[u] == 1)
		{
			vis[u] = 2;
			t = u;
			res.push_back(u);
			return 1;
		}
	vis[u] = 2;

	for (auto v : edge[u])
		{
			if (vis[v] != 2 && dfs(v))
				{
					res.push_back(u);
					return 1;
				}
		}
	return 0;
}

void dfs_cl(int u)
{
	vis[u] = 1;
	for (auto v : edge[u])if (vis[v] == 2 && v != s)dfs_cl(v);
}

bool dfs1(int u, vector<int>&ans)
{
	ans.push_back(u);
	book[u] = 1;
	if (u == t)return 1;
	for (auto v : edge[u])if (vis[v] != 2 || v == t)
			{
				if (v == s || book[v])continue;
				if (dfs1(v, ans))return 1;
			}
	ans.pop_back();
	return 0;
}

bool solve()
{
	for (auto v : edge[s])
		{
			if (dfs(v))return 1;
			dfs_cl(v);
		}
	return 0;
}

void mysolve()
{
	cin >> n >> m >> s;
	int x, y;
	for (int i = 1; i <= m; ++i)cin >> x >> y, edge[x].push_back(y);
	vis[s] = 2;
	if (solve())
		{
			res.push_back(s);
			cout << "Possible" << endl;
			vector<int>ans1;
			dfs1(s, ans1);
			reverse(res.begin(), res.end());
			cout << (int)ans1.size() << endl;
			for (auto v : ans1)cout << v << " ";
			cout << endl;
			cout << (int)res.size() << endl;
			for (auto v : res)cout << v << " ";
			cout << endl;
		}
	else cout << "Impossible" << endl;
}

signed main()
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
