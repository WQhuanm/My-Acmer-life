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

int n, m;
int a[N], b[N], c[N], d[N];
void mysolve()
{
	cin >> n;
	map<int, int>mp;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)cin >> c[i], mp[a[i]] = c[i];
	cin >> m;
	for (int i = 1; i <= m; ++i)cin >> b[i];
	for (int i = 1; i <= m; ++i)cin >> d[i];
	if (m > n)return cout << 0 << endl, void();
	int ans = 1;
	for (int i = 1; i <= m; ++i)
		{
			if (!mp.count(b[i]))return cout << 0 << endl, void();
			if (mp[b[i]] < d[i])return cout << 0 << endl, void();
			if (mp[b[i]] != d[i])ans = ans * 2 % mod;
		}
	mp.clear();
	for (int i = 1; i <= m; ++i)mp[b[i]] = 1;
	for (int i = 1; i <= n; ++i)if (!mp.count(a[i]))ans = ans * 2 % mod;
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
