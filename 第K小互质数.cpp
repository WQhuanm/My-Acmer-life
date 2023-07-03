#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

namespace prime_fac
{
	const int S = 8; // 随机算法判定次数，8~10 就够了

	// 龟速乘
	long long mult_mod(long long a, long long b, long long c)
	{
		a %= c, b %= c;
		long long ret = 0;
		long long tmp = a;
		while (b)
			{
				if (b & 1)
					{
						ret += tmp;
						if (ret > c) ret -= c;
					}
				tmp <<= 1;
				if (tmp > c) tmp -= c;
				b >>= 1;
			}
		return ret;
	}

	// 快速幂
	long long qow_mod(long long a, long long n, long long _mod)
	{
		long long ret = 1;
		long long temp = a % _mod;
		while (n)
			{
				if (n & 1) ret = mult_mod(ret, temp, _mod);
				temp = mult_mod(temp, temp, _mod);
				n >>= 1;
			}
		return ret;
	}

	// 是合数返回true，不一定是合数返回false
	bool check(long long a, long long n, long long x, long long t)
	{
		long long ret = qow_mod(a, x, n);
		long long last = ret;
		for (int i = 1; i <= t; i++)
			{
				ret = mult_mod(ret, ret, n);
				if (ret == 1 && last != 1 && last != n - 1) return true;
				last = ret;
			}
		if (ret != 1) return true;
		return false;
	}

	// 是素数返回true，不是返回false
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	bool Miller_Rabin(long long n)
	{
		if (n < 2) return false;
		if (n == 2) return true;
		if ((n & 1) == 0) return false;
		long long x = n - 1;
		long long t = 0;
		while ((x & 1) == 0)
			{
				x >>= 1;
				t++;
			}

		for (int i = 0; i < S; i++)
			{
				long long a = rng() % (n - 1) + 1;
				if (check(a, n, x, t))
					return false;
			}

		return true;
	}

	long long factor[100];// 存质因数
	int tol; // 质因数的个数，0~tol-1

	long long gcd(long long a, long long b)
	{
		long long t;
		while (b)
			{
				t = a;
				a = b;
				b = t % b;
			}
		if (a >= 0) return a;
		return -a;
	}

	long long pollard_rho(long long x, long long c)
	{
		long long i = 1, k = 2;
		long long x0 = rng() % (x - 1) + 1;
		long long y = x0;
		while (1)
			{
				i++;
				x0 = (mult_mod(x0, x0, x) + c) % x;
				long long d = gcd(y - x0, x);
				if (d != 1 && d != x) return d;
				if (y == x0) return x;
				if (i == k)
					{
						y = x0;
						k += k;
					}
			}
	}
	// 对n质因数分解，存入factor，k一般设置为107左右
	void findfac(long long n, int k)
	{
		if (n == 1) return;
		if (Miller_Rabin(n))
			{
				factor[tol++] = n;
				return;
			}
		long long p = n;
		int c = k;
		while (p >= n) p = pollard_rho(p, c--);
		findfac(p, k);
		findfac(n / p, k);
	}
	vector<long long> fac(long long n)
	{
		tol = 0;
		vector<long long>ret;
		findfac(n, 107);
		for (int i = 0; i < tol; i++)ret.push_back(factor[i]);
		sort(ret.begin(), ret.end());
		ret.erase((unique(ret.begin(), ret.end())), ret.end());//去重
		return ret;
	}
}
//vector<long long>fac = prime_fac::fac(n);
vector<long long>fac;
int cnt;
int binarys(ll x)
{
	ll sum = x;
	for (int i = 1; i < (1 << cnt); ++i)
		{
			ll tmp = 1;
			int tot = 0;
			for (int j = 0; (1 << j) <= i; ++j)if ((i >> j) & 1)tot++, tmp *= fac[j];
			tmp = x / tmp;
			if (tot & 1)sum -= tmp;
			else sum += tmp;
		}
	return sum;
}

void mysolve()
{
	ll n, k;
	cin >> n >> k;
	fac = prime_fac::fac(n);
	cnt = (int)fac.size();
	ll l = 1, r = n;
	ll ans = 1;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (binarys(mid) < k)l = mid + 1;
			else ans = mid, r = mid - 1;
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
