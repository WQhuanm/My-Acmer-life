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
const int N = 2e5 + 10;

int n, k;
ll pre[N], inv[N];

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

ll C(int n, int m)
{
	if (m > n)return 0;
	return pre[n] * inv[m] % mod * inv[n - m] % mod;
}

ll g[N], f[N];

void mysolve()
{
	cin >> n >> k;
	pre[0] = 1;
	int lim = 2e5+5;
	for (int i = 1; i <= lim; ++i)pre[i] = pre[i - 1] * i % mod;
	inv[lim] = fastmi(pre[lim], mod - 2);
	for (int i = lim - 1; ~i; --i)inv[i] = inv[i + 1] * (i + 1) % mod;

	for (int i = 0; i <= n; ++i) //至少i个空集合
		{
			if (k <= n - i)g[i] = pre[k + 1];
			else g[i] = pre[n - i+1] * fastmi(n - i+1, k-(n-i)) % mod;
		}
	ll ans = 0;
	for (int i = 0; i <= n; ++i)
		{
			f[i] = (g[i] - g[i + 1] + mod) % mod;
			ans = (ans + f[i] * pre[n] % mod * inv[i] % mod) % mod;
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
