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
const int mod = 1e9 + 7;

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
	int n, p;
	cin >> n >> p;
	if (!n)cout << 0 << endl;
	else if (n < 6)cout << (n / 2 + 1) * 15 % mod << endl;
	else
		{
			ll ans = (n / 2 + 1) * 15 % mod;
			if (n & 1)
				{
					int t = n / 6;
					ll np = fastmi(1 - p + mod, t), yp = (1 - np + mod) % mod, p_one = p * fastmi(1 - p + mod, t - 1) % mod * t % mod;
					ll p_more = (1 + (mod - np) + (mod - p_one)) % mod, p_ans = (yp * 7 % mod + np * p_one % mod * 3 % mod + (t > 1 ? np * p_more % mod * 6 % mod : 0) % mod);
					ans = (ans + yp * p_ans  % mod + np * (t > 1 ? p_more * p_ans % mod : 0) % mod) % mod;
				}
			cout << ans << endl;
		}
}

int32_t main()
{
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
