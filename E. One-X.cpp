#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<ll, ll> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

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
void mysolve()
{
	cin >> n;
	map<ll, pii>mp;
	mp[n] = {1, 1};
	ll ans = 0;
	while (!mp.empty())
		{
			auto [len, now] = *prev(mp.end());
			auto [val, cnt] = now;
			int l = (len + 1) / 2, r = len / 2;
			if (l && r)
				{
					mp[l] = {(mp[l].first + val * 2) % mod, (mp[l].second + cnt) % mod};
					mp[r] = {(mp[r].first + val * 2 + cnt) % mod, (mp[r].second + cnt) % mod};
					ans = (ans + val * (fastmi(2, l) - 1 + mod) % mod * (fastmi(2, r) - 1 + mod) % mod) % mod;
				}
			else ans = (ans + val) % mod;
			mp.erase(prev(mp.end()));
		}
	cout << ans << endl;
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
