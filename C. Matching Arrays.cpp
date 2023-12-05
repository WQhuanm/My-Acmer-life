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

int n, x;
pii b[N], a[N];

int ans[N];
void mysolve()
{
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)cin >> a[i].first, a[i].second = i;
	for (int i = 1; i <= n; ++i)cin >> b[i].first, b[i].second = i;
	sort(a + 1, a + 1 + n, greater<pii>());
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= x; ++i)if (a[i].first <= b[x - i + 1].first)return cout << "NO" << endl, void();
	for (int i = 1; i <= x; ++i)ans[a[i].second] = b[x - i + 1].first;
	int j = n;
	for (int i = x + 1; i <= n; ++i)
		{
			if (b[j].first < a[i].first)return cout << "NO" << endl, void();
			ans[a[i].second] = b[j--].first;
		}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
}

signed main()
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
