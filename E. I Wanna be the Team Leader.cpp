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
const int N = 2e5 + 10, M = 25;

int n, m;
int nx[M][N], b[N];
pii a[N];
vector<int>c[N];

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + 1 + n);
	for (int k = 0; k < m; ++k)cin >> b[k];
	for (int k = 0; k < m; ++k)
		{
			nx[k][n + 1] = 1;
			for (int i = n; i; --i)
				{
					int p = i + (b[k] + a[i].first - 1) / a[i].first - 1;
					if (p > n)p = inf;
					nx[k][i] = p;
				}
		}
	for (int k = 0; k < m; ++k)for (int i = n - 1; i; --i)nx[k][i] = min(nx[k][i + 1], nx[k][i]);
	vector<int>dp(1 << m, inf), kind(1 << m);
	dp[0] = 0;
	for (int i = 0; i < (1 << m); ++i)if (dp[i] < n)
			{
				for (int k = 0; k < m; ++k)if (!((i >> k) & 1))
						{
							int cur = nx[k][dp[i] + 1];
							if (cur < dp[i | (1 << k)])
								{
									dp[i | (1 << k)] = cur;
									kind[i | (1 << k)] = k;
								}
						}
			}
	int now = (1 << m) - 1;
	if (dp[now] > n)return cout << "NO" << endl, void();
	cout << "YES" << endl;
	while (now)
		{
			int last = dp[now], k = kind[now];
			now ^= (1 << k);
			int st = dp[now] + 1;
			for (int i = st; i <= last; ++i)if (nx[k][i] == last)st = i;
			for (int i = st; i <= last; ++i)c[k].push_back(a[i].second);
		}
	for (int k = 0; k < m; ++k)
		{
			cout << c[k].size() << " ";
			for (auto v : c[k])cout << v << " ";
			cout << endl;
		}
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
