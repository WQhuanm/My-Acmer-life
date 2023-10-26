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

int n, s;
struct node
{
	int c, p;
	bool operator<(const node&k)const
	{
		return p > k.p;
	}
} a[N];
void mysolve()
{
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)cin >> a[i].c;
	for (int j = 1; j <= n; ++j)cin >> a[j].p;
	sort(a + 1, a + 1 + n);
	int num = min(2000ll, n);
	vector dp(2, vector<ll>(2010, INF));
	int p = 0;
	dp[p][0] = 0;
	for (int i = 1; i <= n; ++i)
		{
			p ^= 1;
			dp[p] = vector<ll>(2010, INF);
			dp[p][0] = 0;
			for (int j = 1; j <= min(num, i); ++j)if (dp[p ^ 1][j] <= s || dp[p ^ 1][j - 1] <= s)
					dp[p][j] = min(dp[p ^ 1][j], dp[p ^ 1][j - 1] + a[i].c + (j - 1) * a[i].p);
		}
	int ans = 0;
	for (int i = 1; i <= num; ++i)if (dp[p][i] <= s)ans = i;
	cout << ans << endl;
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
