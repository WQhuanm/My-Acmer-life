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
const int mod = 998244353;
const int N = 1e6 + 10;
ll pre[N], inv[N];
ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			base = base * base % mod;
			power >>= 1;
		}
	return ans;
}

ll C(int n, int m)
{
	if (n < m || n < 0 || m < 0)return 0;
	return pre[n] * inv[m] % mod * inv[n - m] % mod;
}
int n, m, k;
void mysolve()
{
	cin >> n >> m >> k;
	ll ans = 0;
	for (int i = 0;  i <= m; ++i)ans = (ans + C(m, i) * (i & 1 ? -1 : 1) *  C(n - k * i - 1, n - m - k * i) % mod + mod) % mod;
	ans = ans * pre[n] % mod * inv[m] % mod;
	cout << ans << endl;
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
	system("pause");
	return 0;
}
