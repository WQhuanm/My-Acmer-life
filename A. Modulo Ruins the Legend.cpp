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
const int N = 3e5 + 10;

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


int n, m;
int a[N];

void mysolve()
{
	cin >> n >> m;
	ll c = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], c += a[i];
	c %= m;
	int x, y, d, g = __gcd(n, m);
	if (n & 1)
		{
			d = 0;
			int k = (m - c + g - 1) / g;
			exgcd(n, m, x, y);
			x = (x * k % m + m) % m;
		}
	else
		{
			int k1 = (m - c + g - 1) / g, c2 = (c + n * (n + 1) / 2) % m, k2 = (m - c2 + g - 1) / g;
			if ((c + k1 * g) % m <= (c2 + k2 * g) % m)
				{
					d = 0;
					exgcd(n, m, x, y);
					x = (x * k1 % m + m) % m;
				}
			else
				{
					d = 1;
					exgcd(n, m, x, y);
					x = (x * k2 % m + m) % m;
				}
		}
	int ans = (c + n * x + n * (n + 1) / 2 * d) % m;
	cout << ans << endl;
	cout << x << " " << d << endl;
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
