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

int a[N], p[N];
int n;

ll slow_mul(ll base, ll power, ll mod)//龟速乘
{
	ll ans = 0;
	while (power)
		{
			if (power & 1)ans = (ans + base) % mod;
			power >>= 1;
			base = (base << 1) % mod;
		}
	return ans;
}

int exgcd(int a, int b, int &x, int &y)//&直接修改值
{
	if (!b)
		{
			x = 1, y = 0;
			return a;
		}
	int gcd = exgcd(b, a % b, y, x); //x继承了深层的y,y就继承深层的x，y再减去(a/b)*y2即-(a/b)*x即可
	y -= (a / b) * x;
	return gcd;
}

int exCRT(int k, int *a, int *p)
{
	int M = p[1], ans = a[1];//初始第一组ans为a[1]+t*p[1]
	for (int i = 2; i <= n; ++i)
		{
			int x, y, c = (a[i] - ans % p[i] + p[i]) % p[i];//转化ans+t*M≡a[i] (mod p[i])为ax≡c(mod p)形式
			int gcd = exgcd(M, p[i], x, y), pg = p[i] / gcd;
			if (c % gcd)return -1;
			x = slow_mul(x, c / gcd, pg);//把扩欧形式ax+by=gcd(a,b)转为ax≡c的形式，即x龟速幂乘c/gcd(M,p)
			ans += x * M;//更新
			M *= pg;
			ans = (ans % M + M) % M;
		}
	return ans;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> p[i] >> a[i];
	cout << exCRT(n, a, p) << endl;
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
