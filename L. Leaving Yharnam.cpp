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
const long long mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 2e6 + 10;

ll pre[N], inv[N], pp[N];

ll C(int n, int m)
{
	if (n < m)return 0;
	return pre[n] * inv[m] % mod * inv[n - m] % mod;
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

int n, g, il, e;
void mysolve()
{
	cin >> n >> g >> il >> e;
	if (2 * n <= g)return cout << 2 * n << endl, void();
	ll ans = 0;
	for (int i = 0; i * 2 <= g; ++i)if (i + (g - 2 * i) <= n)
			{
				int te = e, til = il;
				int p = C(n, i) * C(n - i, g - 2 * i) % mod * pp[g - 2 * i] % mod, sum = g;
				int now = g - 2 * i, last = n - i - (g - 2 * i); //剩余单座，剩余双座
				if (te <= now)//坐不满
					{
						sum += te;
						if (til <= last)sum += til;
						else
							{
								now -= te;
								til -= last;
								if (til <= now)sum += last;
								else
									{
										til -= now;
										sum += max(0ll, last - til);
									}
							}
					}
				else  //超了，可能有人落单
					{
						sum += now, te -= now;
						if (te <= last * 2)
							{
								sum += te, last -= te / 2;
								te = te & 1;
								last -= te, sum -= te;
								if (til <= last)sum += til;
								else
									{
										if (te)sum++, til--;
										sum += max(0ll, 2 * last - til);
									}
							}
						else
							{
								sum += last * 2;
							}
					}
				ans = (ans + sum * p % mod) % mod;
//				cout << sum << endl;
			}
	ans = ans * fastmi(C(2 * n, g), mod - 2) % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	pre[0] = pp[0] = 1;
	int lim = N - 5;
	for (int i = 1; i <= lim; ++i)pp[i] = pp[i - 1] * 2 % mod, pre[i] = pre[i - 1] * i % mod;
	inv[lim] = fastmi(pre[lim], mod - 2);
	for (int i = lim - 1; ~i; --i)inv[i] = inv[i + 1] * (i + 1) % mod;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
