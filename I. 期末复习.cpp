#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
#define int ll
//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int w[N], a[N];

int f(int k, int x)
{
	int h = k / x;
	if (k % x >= x * 1.0 / 2)h++;
	if (h >= 95)return 500;
	else if (h >= 60)
		{
			double tmp = 500 - 10 * (95 - h);
			return tmp;
		}
	else return 0;
}

int32_t main()
{
	int t, n, g;
	cin >> t;
	while (t--)
		{
			int sum = 0;
			cin >> n >> g;
			for (int i = 1; i <= n; ++i)cin >> w[i], sum += w[i];
			for (int i = 1; i <= n; ++i)cin >> a[i];
			int l = 0, r = INF, ans = INF;
			while (l <= r)
				{
					int mid = l + ((r - l) >> 1);
					double tmp = 0;
					for (int i = 1; i <= n; ++i)tmp += f(mid, a[i]) * w[i];
					if (tmp >= g  * sum)
						{
							ans = mid, r = mid - 1;
						}
					else l = mid + 1;
				}
			cout << ans << endl;
		}

	return 0;
}
