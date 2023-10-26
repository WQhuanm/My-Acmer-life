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
const int N = 5010;

int n;
int a[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	if (!count(a + 1, a + 1 + n, 0))return cout << 0 << endl, void();
	sort(a + 1, a + 1 + n);
	vector<int>cnt(n + 1);
	int mex = 0;
	for (int i = 1; i <= n && a[i] <= n; ++i)
		{
			if (a[i] > mex)break;
			else if (a[i] == mex)mex++;
			cnt[a[i]]++;
		}
	vector<int>dp(n + 1);
	for (int i = mex - 1; i >= 0; --i)
		{
			dp[i] = inf;
			for (int j = i + 1; j <= mex; ++j)
				dp[i] = min(dp[i], dp[j] + (cnt[i] - 1) * j + i);
		}
	cout << dp[0] << endl;

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
