#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e4 + 10;

ll hibit(ll x)
{
	if (!x)return 0;
	if (x == (1ll << 62))return (1ll << 62); //特判零
	return 1ull << (63 - __builtin_clzll(x)/*这个函数返回的是二进制下前导零的个数*/);
}

int n;
bool ans[N];
ll a[N], l[N], r[N], sum[N];
bool fl[N], fr[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], l[i] = r[i] = 0, ans[i] = fl[i] = fr[i] = 0, sum[i] = sum[i - 1] ^ a[i];
	if (n == 1)return cout << 1 << endl, void();
	l[1] = r[n] = hibit(sum[n]);
	if (!l[1])fl[1] = fr[n] = 1;
	for (int len = n - 1; len; --len)for (int i = 1; i + len - 1 <= n; ++i)
			{
				int j = i + len - 1;
				ll now = sum[j] ^ sum[i - 1];
				if (fr[j] || fl[i] || now & r[j] || now & l[i])
					{
						ll p = hibit(now);
						r[j] |= p, l[i] |= p;
						if (!p)fl[i] = fr[j] = 1;
						if (len == 1)ans[i] = 1;
					}
			}
	for (int i = 1; i <= n; ++i)cout << ans[i];
	cout << endl;
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
