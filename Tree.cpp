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
const ll a1 = 998244353, a2 = 1e9 + 7, a3 = -a1 - a2;
const int N = 3e5 + 10;

int n, rt, sum;
ll ans;
bool vis[N];
int  sz[N], mx[N], a[N], q[N];
ll dis[N];
vector<int>edge[N];

void get_rt(int u, int f)//获取当前子树重心rt
{
	sz[u] = 1, mx[u] = 0;
	for (auto v : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum - mx[u]);
	if (mx[u] < mx[rt])rt = u;
}

map<ll, int>mp;
void get_dis(int u, int f)//处理儿子树每个点获得的贡献
{
	q[++q[0]] = dis[u];
	for (auto v : edge[u])
		if (!vis[v] && v != f)dis[v] = dis[u] + a[v], get_dis(v, u);
}

void cal(int u)//cal函数处理子树每个儿子树获得的贡献
{
	//在清空信息时，需要开队列记录，保证复杂度
	mp.clear();
	mp[0] = 1;
	for (auto v : edge[u])if (!vis[v])
			{
				q[0] = 0;
				dis[v] = a[u] + a[v], get_dis(v, u);
				for (int i = q[0]; i; --i)
					if (mp.count(-q[i]))
						ans += mp[-q[i]];
				for (int i = q[0]; i; --i)mp[q[i] - a[u]]++;
			}
}

void solve(int u)
{
	vis[u] = 1, cal(u);
	for (auto v : edge[u])if (!vis[v])
			{
				rt = 0, sum = sz[v];
				get_rt(v, u), get_rt(rt, 0);//第一遍找重心，第二遍重新划分sz
				solve(rt);//分治rt子树
			}
}

string s;
void mysolve()
{
	cin >> n >> s;
	int x, y;
	for (int i = 1; i <= n; ++i)a[i] = (s[i - 1] == 'a' ? a1 : s[i - 1] == 'b' ? a2 : a3), edge[i].clear(), vis[i] = 0;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	mx[rt = 0] = inf, sum = n;//sum为当前子树大小
	get_rt(1, 0), get_rt(rt, 0);
	solve(rt);
	cout << ans << endl;
}

int32_t main()
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
