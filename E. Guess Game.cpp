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
const int N = 3e6 + 10;

int ch[N][2], cnt[N], ed[N]; //N取决与有多少个不同字符串，常数巨大（接近n^2)
int tot;
ll ans;

inline void insert(int x)
{
	int p = 0;
	int one = 0;
	for (int i = 31; ~i; --i)
		{
			int t = (x >> i) & 1;

			if (!ch[p][t])ch[p][t] = ++tot;
			ans = (ans + 1ll * (one * 2 + 3) * cnt[ch[p][t ^ 1]] % mod) % mod;
			p = ch[p][t];
			cnt[p]++;
			if (t)one++;
		}
	ans = (ans + 1ll * (one + 1) * 2 * ed[p] % mod) % mod;
	ed[p]++;
	ans = (ans + one + 1) % mod;
}

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
int a[N];

void mysolve()
{
	cin >> n;
	for (int i = 0; i <= tot; ++i)cnt[i] = ch[i][0] = ch[i][1] = ed[i] = 0;
	tot = ans = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			insert(a[i]);
		}
	ans = ans * fastmi(n * n % mod, mod - 2) % mod ;
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
