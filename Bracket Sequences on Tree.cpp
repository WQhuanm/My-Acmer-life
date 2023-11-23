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
const int N = 1e5 + 10;

typedef unsigned long long ull;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();//time随机数
ull h[N];

ull shift(ull x)//shift函数增加混乱度
{
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
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

int n;
vector<int>edge[N];
ll dp[N], pre[N], inv[N], ans;
map<ull, bool>mp;

void pre_dfs(int u, int f)
{
	h[u] = 1, dp[u] = 1;
	int cnt = 0;
	map<ull, int>sum;
	for (auto v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
				h[u] += shift(h[v]), sum[h[v]]++;
				dp[u] = dp[u] * dp[v] % mod, cnt++;
			}
	dp[u] = dp[u] * pre[cnt] % mod;
	for (auto [v, now] : sum)dp[u] = dp[u] * inv[now] % mod;
}

void dfs(int u, int f)
{
	ll tmp = 1, cnt = 0;
	map<ull, int>sum;
	for (auto v : edge[u])tmp = tmp * dp[v] % mod, cnt++, sum[h[v]]++;
	tmp = tmp * pre[cnt] % mod;
	for (auto [v, now] : sum)tmp = tmp * inv[now] % mod;
	if (!mp.count(h[u]))
		{
			mp[h[u]] = 1;
			ans = (ans + tmp) % mod;
		}
	dp[u] = tmp;
	if (cnt)tmp = tmp * inv[cnt] % mod * pre[cnt - 1] % mod;
	for (auto v : edge[u])if (v != f)
			{
				ll now = dp[u];
				ull nh = h[u];
				dp[u] = tmp * pre[sum[h[v]]] % mod * inv[sum[h[v]] - 1] % mod * fastmi(dp[v],mod-2)%mod;
				h[u] -= shift(h[v]);
				h[v] += shift(h[u]);
				dfs(v, u);
				dp[u] = now, h[u] = nh;
			}
}

void mysolve()
{
	mp.clear(), ans = 0;
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; ++i)edge[i].clear();
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0), dfs(1, 0);
	cout << ans << endl;
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	pre[0] = 1;
	for (int i = 1; i <= N - 5; ++i)pre[i] = pre[i - 1] * i % mod;
	inv[N - 5] = fastmi(pre[N - 5], mod - 2);
	for (int i = N - 5; i; --i)inv[i - 1] = inv[i] * i % mod;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
