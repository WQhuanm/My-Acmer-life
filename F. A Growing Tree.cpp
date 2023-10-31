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
const int N = 1e6 + 10;

vector<int>edge[N];
vector<pii>val[N];
int tot;
int t[N], num[N];
ll ans[N];
int q;
void add(int x, int w)
{
	if (!x)return t[x] += w, void();
	for (int i = x; i <= q; i += i & -i)t[i] += w;
}
ll ask(int x)
{
	if (!x)return t[0];
	ll ans = t[0];
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void dfs(int u)
{
	for (auto [t, w] : val[u])add(q - t, w);
	ans[u] = ask(q - num[u]);
	for (auto v : edge[u])dfs(v);
	for (auto [t, w] : val[u])add(q - t, -w);
}

void mysolve()
{
	cin >> q;
	for (int i = 1; i <= tot; ++i)ans[i] = 0, val[i].clear(), edge[i].clear();
	for (int i = 0; i <= q; ++i)t[i] = 0;
	tot = 1, num[1] = 0;
	int x, y, z;
	for (int i = 1; i <= q; ++i)
		{
			cin >> z;
			if (z == 1)cin >> x, edge[x].push_back(++tot), num[tot] = i;
			else cin >> x >> y, val[x].push_back({i, y});
		}
	dfs(1);
	for (int i = 1; i <= tot; ++i)cout << ans[i] << " \n"[i == tot];
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
