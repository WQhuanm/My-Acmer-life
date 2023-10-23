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

const int lim = 130;
map<int, vector<int>>dp;

vector<int> operator+(const vector<int>&a, const vector<int>&b)
{
	vector<int>ans(lim);
	for (int i = 1; i < lim; ++i)ans[i] = (a[i] + b[i]) % mod;
	return ans;
}

vector<int> count_dep(int n)
{
	vector<int>ans(lim);
	int dep = 0;
	while ((1ll << (dep + 1)) - 1 <= n)
		{
			ans[dep + 1] = (1ll << dep) % mod;
			dep++;
		}
	n -= (1ll << dep) - 1;
	if (n)
		{
			ans[dep + 1] = n % mod;
		}
	return ans;
}

vector<int> dfs(int n)
{
	if (!n)return vector<int>(lim);
	if (dp.count(n))return dp[n];
	vector<int>ans(lim);
	ans[1] = 1;
	if (n == 1)return dp[n] = ans;
	int dep = 0, l, r;
	while ((1ll << dep) - 1 < n)dep++;
	if (n == (1ll << dep) - 1)//满二叉树
		{
			l = r = n / 2;
		}
	else
		{
			l = min((1ll << (dep - 1)) - 1, (1ll << (dep - 2)) - 1 + n - (1ll << (dep - 1)) + 1);
			r = n - l - 1;
		}
	vector cntl = count_dep(l), cntr = count_dep(r);
	for (int i = 2; i < lim; ++i)ans[i] = (ans[i] + cntl[i - 1] + cntr[i - 1]) % mod;
	for (int i = 3; i < lim; ++i)for (int k = 1; k < i - 1; ++k)ans[i] = (ans[i] + cntl[k] * cntr[i - 1 - k] % mod) % mod;
	return dp[n] = ans + dfs(l) + dfs(r);
}
int n, m;
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

ll pre[N][lim];

void mysolve()
{
	cin >> n >> m;
	vector ans = dfs(n);
	ll res = 0;
	ll p = fastmi(m, n), inv = fastmi(m, mod - 2);
	for (int k = 1; k < lim; ++k)
		{
			p = p * inv % mod;
			for (int i = 1; i <= m; ++i)
				{
					res = (res + p * ((pre[i][k] - pre[i - 1][k] + mod) % mod) % mod * i % mod * ans[k] % mod) % mod;
				}
		}
	cout << res << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	for (int i = 1; i <= N - 5; ++i)
		{
			pre[i][0] = 1;
			for (int j = 1; j < lim; ++j)pre[i][j] = pre[i][j - 1] * i % mod;
		}
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
