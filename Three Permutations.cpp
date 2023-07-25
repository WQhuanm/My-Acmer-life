#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 1e18
#define int              long long
const int N = 3e5 + 10;

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
	for (int i = 2; i <= k; ++i)
		{
			int x, y, c = (a[i] - ans % p[i] + p[i]) % p[i];//转化ans+t*M≡a[i] (mod p[i])为ax≡c(mod p)形式
			int gcd = exgcd(M, p[i], x, y), pg = p[i] / gcd;
			if (c % gcd)return inf;
			x = slow_mul(x, c / gcd, pg);//把扩欧形式ax+by=gcd(a,b)转为ax≡c的形式，即x龟速幂乘c/gcd(M,p)
			ans += x * M;//更新
			M *= pg;
			ans = (ans % M + M) % M;
		}
	return ans;
}

int n;
int a[N], b[N], c[N], ia[N], ib[N], ic[N], la[N], lb[N], lc[N];
int lena, lenb, lenc;
int ta[5], p[5];
int solve(int x, int y, int z)
{
	if (la[x] == -1 || lb[y] == -1 || lc[z] == -1)return inf;
	ta[1] = la[x], p[1] = lena;
	ta[2] = lb[y], p[2] = lenb;
	ta[3] = lc[z], p[3] = lenc;
	return exCRT(3, ta, p);
}
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], ia[a[i]] = i, la[i] = -1;
	for (int i = 1; i <= n; ++i)cin >> b[i], ib[b[i]] = i, lb[i] = -1;
	for (int i = 1; i <= n; ++i)cin >> c[i], ic[c[i]] = i, lc[i] = -1;
	for (int i = 1; la[i] == -1; i = a[b[c[i]]], ++lena)la[i] = lena;
	for (int i = 1; lb[i] == -1; i = b[c[a[i]]], ++lenb)lb[i] = lenb;
	for (int i = 1; lc[i] == -1; i = c[a[b[i]]], ++lenc)lc[i] = lenc;

	int q, x, y, z;
	cin >> q;
	while (q--)
		{
			cin >> x >> y >> z;
			ll ans = inf;
			ans = min(ans, solve(x, y, z) * 3);
			ans = min(ans, solve(ic[z], ia[x], ib[y]) * 3 + 1);
			ans = min(ans, solve(ic[ib[y]], ia[ic[z]], ib[ia[x]]) * 3 + 2);
			cout << (ans >= inf ? -1 : ans) << endl;
		}
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
