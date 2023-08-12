#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

int n;

namespace prime_fac
{
	long long max_factor;
	long long factor[100];// 存质因数
	int tot; // 质因数的个数

	long long gcd(long long a, long long b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	// 快速幂
	long long qow_mod(long long base, long long power, long long _mod)
	{
		long long ans = 1;
		while (power)
			{
				if (power & 1)ans = (__int128)ans * base % _mod;
				base = (__int128)base * base % _mod;
				power >>= 1;
			}
		return ans;
	}

	// 是素数返回true，不是返回false
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	bool Miller_Rabin(long long p)    // 判断素数
	{
		if (p < 2) return 0;
		if (p == 2) return 1;
		if (p == 3) return 1;
		long long d = p - 1, r = 0;
		while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
		for (long long k = 0; k < 10; ++k)
			{
				long long a = rng() % (p - 2) + 2;
				long long x = qow_mod(a, d, p);
				if (x == 1 || x == p - 1) continue;
				for (int i = 0; i < r - 1; ++i)
					{
						x = (__int128)x * x % p;
						if (x == p - 1) break;
					}
				if (x != p - 1) return 0;
			}
		return 1;
	}

	long long Pollard_Rho(long long x)
	{
		long long s = 0, t = 0;
		long long c = (long long)rng() % (x - 1) + 1;
		int step = 0, goal = 1;
		long long val = 1;
		for (goal = 1;; goal *= 2, s = t, val = 1)    // 倍增优化
			{
				for (step = 1; step <= goal; ++step)
					{
						t = ((__int128)t * t + c) % x;
						val = (__int128)val * abs(t - s) % x;
						if ((step % 127) == 0)
							{
								long long d = gcd(val, x);
								if (d > 1) return d;//找到因子d
							}
					}
				long long d = gcd(val, x);
				if (d > 1) return d;
			}
	}

	void max_fac(long long x)
	{
		if (x <= max_factor || x < 2) return;
		if (Miller_Rabin(x))                // 如果x为质数
			{
				max_factor = max(max_factor, x);  // 更新答案
				return;
			}
		long long p = x;
		while (p >= x) p = Pollard_Rho(x);  // 使用该算法，直到寻找到因子
		while ((x % p) == 0) x /= p;//对x剥离p因子
		max_fac(x), max_fac(p);  // 继续向下分解x和p
	}

	long long get_max_factor(long long n)
	{
		max_factor = 1;
		max_fac(n);
		return max_factor;
	}

	// 对n质因数分解，存入factor，k一般设置为107左右
	void findfac(long long x)
	{
		if (x < 2)return;
		if (Miller_Rabin(x))
			{
				factor[++tot] = x;
				return;
			}
		long long p = x;
		while (p >= x) p = Pollard_Rho(x);  // 使用该算法，直到寻找到因子
		while ((x % p) == 0) x /= p;//对x剥离p因子
		findfac(p), findfac(x / p);
	}

	vector<long long> fac(long long n)
	{
		tot = 0;
		vector<long long>ret;
		findfac(n);
		for (int i = 1; i <= tot; i++)ret.push_back(factor[i]);
		sort(ret.begin(), ret.end());
		ret.erase((unique(ret.begin(), ret.end())), ret.end());//去重
		return ret;
	}
}
//vector<long long>fac = prime_fac::fac(n);//获取所有质因子
//ll mx = prime_fac::get_max_factor(n); //获取n的最大质因子
//bool fl = prime_fac::Miller_Rabin(n); //判断n是不是质数
void mysolve()
{
	cin >> n;
	if (prime_fac::Miller_Rabin(n))
		{
			cout << "Prime" << endl;
		}
	else cout << prime_fac::get_max_factor(n) << endl;
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
