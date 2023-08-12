#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
//#define int ll
const int N =  5;
const int mod = 998244353;

int n = 2;
struct mat
{
	ll t[N][N];
	mat()
	{
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)t[i][j] = 0;
	}
	void unit_mat()
	{
		for (int i = 1; i <= n; ++i)t[i][i] = 1;
	}
	mat operator*(const mat&b)const
	{
		mat ans;
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
				{
					ans.t[i][j] = 0;
					for (int k = 1; k <= n; ++k)ans.t[i][j] = (ans.t[i][j] + t[i][k] * b.t[k][j] % mod) % mod;
				}
		return ans;
	}
} a;

mat fastmi(mat base, ll power)
{
	mat ans;
	ans.unit_mat();
	while (power)
		{
			if (power & 1)ans = ans * base;
			power >>= 1, base = base * base;
		}
	return ans;
}

ll q_pow(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			power >>= 1, base = base * base % mod;
		}
	return ans;
}
void mysolve()
{
	ll n, m;
	cin >> n >> m;
	n %= mod;
	ll n1 = (n - 1 + mod) % mod;
	ll invn = q_pow(n * n % mod, mod - 2) ;
	a.t[1][1] = (n1 * n1 % mod - 1 + mod) % mod * invn % mod;
	a.t[2][1] = 2 * invn % mod;
	a.t[2][2] = 1;
	a = fastmi(a, m);
	ll ans = (a.t[1][1] + a.t[2][1]) % mod;
	ll res = (n + (mod - n * ans % mod)) % mod;
	cout << res << endl;
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
