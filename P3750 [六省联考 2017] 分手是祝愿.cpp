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
const long long mod = 1e5 + 3, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e5 + 10;

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			base = base * base % mod, power >>= 1;
		}
	return ans;
}

bool a[N];

void check(int x)
{
	for (int i = 1; i * i <= x; ++i)if (x % i == 0)
			{
				a[i] ^= 1;
				if (i != x / i)a[x / i] ^= 1;
			}
}

int n, k;
ll dp[N];

void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int cnt = 0;
	for (int i = n; i; --i)if (a[i])cnt++, check(i);
	ll ans = 1;
	for (int i = 1; i <= n; ++i)ans = ans * i % mod;
	if (cnt <= k)return cout << ans * cnt % mod << endl, void();
	dp[n] = 1;
	for (int i = n - 1; i >= 0; --i)dp[i] = (n + (n - i) * dp[i + 1] % mod) % mod * fastmi(i, mod - 2) % mod;
	ll sum = 0;
	for (int i = cnt; i > k; --i)sum = (sum + dp[i]) % mod;
	sum = (sum + k) % mod;
	ans = ans * sum % mod;
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
