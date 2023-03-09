#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;
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

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n, p, q, x;
	cin >> t;
	while (t--)
		{
			cin >> n >> p >> q;
			ll P = p * fastmi(q, mod - 2) % mod, RP = (mod + 1 - P) % mod;
			ll ans = 1;
			for (int i = 1; i <= n; ++i)
				{
					cin >> x;
					ans = ans * (P * x % mod + RP) % mod;
				}
			ans = (mod + ans - fastmi(RP, n)) % mod;
			cout << ans << endl;
		}

	return 0;
}
