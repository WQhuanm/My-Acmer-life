#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;
const int mod = 998244353;
int a[3];

ll fastmi(ll base, ll power)//快速幂求逆元
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

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;//n从表示一个点转化为表示一个环
	n /= 3;
	ll ans = 1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[0] >> a[1] >> a[2];//3点一个环
			sort(a, a + 3);//
			if (a[0] == a[2])ans = (ans * 3) % mod;//
			else if (a[0] == a[1])ans = (ans * 2) % mod;
		}
	ll tmp = 1;
	for (int i = 1; i <= n / 2; ++i)//求组合数C(n/2,n)
		{
			ans = (ans * (n / 2 + i)) % mod;
			tmp = tmp * i % mod;
		}
	ans = (ans * fastmi(tmp, mod - 2)) % mod;
	cout << ans << endl;
	return 0;
}
