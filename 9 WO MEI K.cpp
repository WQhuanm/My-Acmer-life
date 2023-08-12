#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 2e5 + 10;

vector<pii>edge[N];
stack<int>s[N];
int n;
int sz[N], cnt[N], a[N], fa[N], cnt0[N];
ll inv[N], pre[N];

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

void dfs(int u, int f)
{
	sz[u] = 1, cnt[u] = 0;
	s[a[u]].push(u);
	for (auto [v, w] : edge[u])if (v != f)
			{
				a[v] = w;
				dfs(v, u);
				sz[u] += sz[v];
			}
	cnt[u] = sz[u];
	while (s[a[u]].top() != u)
		{
			int v = s[a[u]].top();
			s[a[u]].pop();
			fa[v] = u;
			cnt[u] -= sz[v];
		}
//	s[a[u]].pop();
}

ll C(int n, int m)
{
	return pre[n] * inv[m] % mod * inv[n - m] % mod;
}

ll nC(int n, int m)
{
	return pre[m] * pre[n - m] % mod * inv[n] % mod;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)edge[i].clear(), fa[i] = 0;
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	a[1] = 0;
	dfs(1, 0);
	s[0].pop();
	for (int i = 1; i <= n; ++i)
		{
			cnt0[i] = n;
			while (!s[i].empty())cnt0[i] -= sz[s[i].top()], s[i].pop();
		}
	ll ans = 0;
	for (int i = 2; i <= n; ++i)
		{
			ans = (ans + cnt[i] * (fa[i] ? cnt[fa[i]] : cnt0[a[i]]) % mod) % mod;
		}
	ll res = 0;
	for (int k = 2; k <= n; ++k)
		{
			res = (res ^ (ans * nC(n, k) % mod * C(n - 2, k - 2) % mod)) ;
		}
	cout << res << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	pre[0] = 1;
	for (int i = 1; i <= N - 5; ++i)pre[i] = pre[i - 1] * i % mod;
	inv[N - 5] = fastmi(pre[N - 5], mod - 2);
	for (int i = N - 6; ~i; --i)inv[i] = inv[i + 1] * (i + 1) % mod;
	while (t--)
		{
			mysolve();
		}
//	system("pause");
	return 0;
}
