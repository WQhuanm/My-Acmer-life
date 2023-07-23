#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

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

void mysolve()
{
	int sum = 3, inv = fastmi(2, mod - 2), p = inv * inv % mod, p_sum = inv, t = 4;
	int n, m;
	cin >> n >> m;
	while (sum <= n)
		{
			p_sum = (p_sum + p) % mod, sum += t;
			p = p * inv % mod, t *= 2;
		}
	ll ans = 1;
	for (int i = n + 1; i <= n + m; ++i)
		{
			while (sum <= i - 1)
				{
					p_sum = (p_sum + p) % mod, sum += t;
					p = p * inv % mod, t *= 2;
				}
			int cnt = min(sum, n + m) - i + 1;
			ans = ans * fastmi(p_sum, cnt) % mod;
			i += cnt - 1;
		}
	cout << ans << endl;
}

int32_t main()
{
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
