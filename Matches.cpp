#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e6 + 10;
const int mod = 998244353;

int a[N];

bool cmp(pii a, pii b)
{
	return min(a.first, a.second) < min(b.first, b.second);
}

void mysolve()
{
	int n;
	cin >> n;
	vector<pii>v;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			if (x != a[i])v.push_back({a[i], x});
			sum += abs(a[i] - x);
		}
	int a = -INF, b = -INF, res = 0;
	sort(v.begin(), v.end(),cmp);
	for (auto [x, y] : v)
		{
			if (x < y)
				{
					res = max(res, min(y, a) - x);
					b = max(b, y);
				}
			else
				{
					res = max(res, min(b, x) - y);
					a = max(a, x);
				}
		}
	cout << sum - 2 * res << endl;
}

int32_t main()
{
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
