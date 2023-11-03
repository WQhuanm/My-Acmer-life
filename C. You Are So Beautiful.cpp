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

int n, a[N];
int pre[N], fix[N];
void mysolve()
{
	cin >> n;
	map<int, bool>mp;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (!mp[a[i]])pre[i] = pre[i - 1] + 1, mp[a[i]] = 1;
			else pre[i] = pre[i - 1];
		}
	fix[n + 1] = 0, mp.clear();
	int ans = 0;
	for (int i = n; i; --i)
		{
			if (!mp[a[i]])fix[i] = fix[i + 1] + 1, mp[a[i]] = 1, ans += pre[i];
			else fix[i] = fix[i + 1];
		}
	cout << ans << endl;
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
