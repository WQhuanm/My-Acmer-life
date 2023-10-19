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

int n;
int fa[N], cnt[N];
int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			power >>= 1, base = base * base % mod;
		}
	return ans;
}

vector<int>edge[N];

int f[N], dep[N];

void dfs(int u, int ff)
{
	f[u] = ff;
	dep[u] = dep[ff] + 1;
	for (auto v : edge[u])if (v != ff)dfs(v, u);
}

pii a[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)fa[i] = i, cnt[i] = 1;
	ll ans = 1;
	int x, y;
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			a[i] = {x, y};
			int fx = find(x), fy = find(y);
			ans = ans * fastmi(cnt[fx] * cnt[fy] % mod, mod - 2) % mod;
			fa[fy] = fx, cnt[fx] += cnt[fy];
		}
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)fa[i] = i;
	for (int i = 1; i < n; ++i)
		{
			x = a[i].first, y = a[i].second;
			int fx = find(x), fy = find(y);
			if (find(f[fx]) == fy)
				{
					fa[fx] = fy;
				}
			else if (find(f[fy]) == fx)fa[fy] = fx;
			else return cout << 0 << endl, void();
		}
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
