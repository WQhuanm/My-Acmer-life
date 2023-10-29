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
//const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int mod, q;

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

bool check(int x, int l, int r)
{
	if (l <= r)return x > l && x <= r;
	else return x > l || x <= r;
}

void mysolve()
{
	cin >> mod >> q;
	int a, b, c, d;
	while (q--)
		{
			cin >> a >> b >> c >> d;
			int s = (a + b) % mod;
			if (s != (c + d) % mod)
				{
					cout << -1 << endl;
					continue;
				}
			int inv = fastmi(s, mod - 2);
			a = a * inv % mod, c = c * inv % mod;
			int i = 0;
			for (; (1ll << i) < mod; ++i)
				{
					int l = (1ll << i) % mod * ((a - 1 + mod) % mod) % mod, r = (1ll << i) % mod * a % mod;
					if (check(c, l, r))break;
				}
			cout << i << endl;
		}
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
