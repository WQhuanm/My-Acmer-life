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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = (1 << 20);

const int B = 19;
int n, q, k;
int a[N];
ll f[B + 1][N], g[B + 1][N];
const int lim = 1 << 20;

void mysolve()
{
	cin >> n >> q;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], sum += lim - a[i];
	for (int p = B; ~p; --p)
		{
			for (int i = 1; i <= n; ++i)if (!((a[i] >> p) & 1))f[p][a[i]]++, g[p][a[i]] += a[i] & ((1 << p) - 1);
			for (int k = 0; k <= B; ++k)for (int i = lim - 1; ~i; --i)if ((i >> k) & 1)f[p][i ^ (1 << k)] += f[p][i], g[p][i ^ (1 << k)] += g[p][i];
		}
	while (q--)
		{
			cin >> k;
			if (k >= sum)cout << (k - sum) / n + lim << endl;
			else
				{
					int cnt = 0, ans = 0;
					for (int p = B; ~p; --p)
						{
							ll cost = cnt * (1 << p) + f[p][ans] * (1 << p) - g[p][ans];
							if (k >= cost)k -= cost, cnt += f[p][ans], ans += 1 << p;
						}
					cout << ans << endl;
				}
		}

}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
