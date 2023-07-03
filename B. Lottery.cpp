#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int l = -1, r;
int n, m, x, k;
vector<int>v;

ll binarys(int x)
{
	while (l + 1 < n && v[l + 1] <= x)l++;
	while (r < n && v[r] < x)r++;
	ll mn = (l < k - 1 ? 0ll : (x + v[l - k + 1]) / 2 + 1);
	ll mx = (r + k - 1 >= n ? m  : (v[r + k - 1] + x + 1) / 2 - 1);
	mx = max(0ll, mx);
	return mx - mn + 1;
}

void mysolve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)cin >> x, v.push_back(x);
	v.push_back(m + 1);
	sort(v.begin(), v.end());
	int ans = binarys(0), p = 0;
	for (int i = 0; i < n; ++i)
		{
			int l = i == 0 ? max(0ll, v[i] - 2) : max(v[i] - 2, v[i - 1] + 3), r = min(v[i] + 2, m);
			for (int j = l; j <= r; ++j)
				{
					ll tmp = binarys(j);
					if (tmp > ans)ans = tmp, p = j;
				}
		}
	cout << ans << " " << p << endl;
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
